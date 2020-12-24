/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <my_runner/runner.h>
#include <my_runner/scene.h>
#include <my_stdio.h>
#include <my_runner/free.h>

static int usage(int ac, char **av)
{
    if (ac > 2 || ac == 1) {
        my_dprintf(2, RED"my_runner: " YELLOW"You have given too "
                "much arguments or too less arguments\n"
                CYAN"Try :"PURPLE" ./my_runner -h for the help\n"DEFAULT);
        return (-1);
    }
    if (av[1][0] != '-')
        return (1);
    if (!my_strcmp(av[1], "-h")) {
        SHOW_HELP
        return (0);
    }
    my_dprintf(2, RED"my_runner :"
            YELLOW"\n\tYou have given a wrong argument !\n"
            CYAN"You can try :" GREEN"\n\t./my_runner -h to"
            " show the help\n"DEFAULT);
    return (-1);
}

bool prepare_map_positions(scene_t *scene, char *file)
{
    reset_player(scene);
    if (scene->enemy)
        destroy_enemy_array(scene);
    if (!map_loader(scene, file)) {
        scene->enemy = NULL;
        return (false);
    }
    sfVector2f pos = VECF(WIN_W + 100, 0);
    srand(time(NULL));
    for (size_t i = 0; scene->enemy[i].enemy_id != -2; i++) {
        pos.x += 200;
        if (scene->enemy[i].enemy_id == -1)
            continue;
        scene->enemy[i].info.pos.x = pos.x;
        sfSprite_setPosition(scene->enemy[i].sprite,
                scene->enemy[i].info.pos);
    }
    return (true);
}


static void check_game_event(scene_t *scene, game_manager_t *manager)
{
    while (CHECK_WINDOW_EVENT(manager->window, manager->event)) {
        if (manager->event.type == sfEvtClosed)
            manager->state = QUIT;
        if (sfKeyboard_isKeyPressed(sfKeySpace) &&
                scene->player.info.state == ON_GROUND) {
            sfSound_play(scene->music.player_jump.sound);
            scene->player.frame.frame = 0;
            scene->player.info.state = JUMPING;
            scene->player.frame.offset = TIME_SHIFT_PLAYER_JUMP;
        }
    }
}

bool init_manager(game_manager_t *manager, char *file)
{
    manager->window = CREATE_WINDOW(WIN_MODE, WINDOW_NAME);
    if (!manager->window)
        return (false);
    SET_FRAME_LIMIT(manager->window, 60);
    manager->clock = sfClock_create();
    manager->score = 0;
    manager->state = MENU;
    manager->map = file;
    return (true);
}

void game_loop(scene_t *scene, game_manager_t *manager)
{
    if (!prepare_map_positions(scene, manager->map)) {
        manager->state= QUIT;
        my_dprintf(2, RED"my_runner: "
                YELLOW"Major error occured\n\t\t"
                "Please make sure that the file exist and is well formatted\n"
                DEFAULT);
        return;
    }
    manager->score = 0;
    sfMusic_play(scene->music.game);
    while (sfRenderWindow_isOpen(manager->window) && manager->state == GAME) {
        check_game_event(scene, manager);
        draw_all_game(scene, manager);
        manager->score += 1;
    }
    sfMusic_stop(scene->music.game);
}

int main(int ac, char **av)
{
    void (*game_ptr[3])(scene_t *, game_manager_t *) = {
        &menu_loop, &game_loop, &free_all};
    int usage_return = 0;
    game_manager_t manager = {0};
    scene_t scene = {0};

    usage_return = usage(ac, av);
    if (usage_return == 0 || usage_return == -1)
        return ((usage_return == 0) ? 0 : 84);
    if (init_scene(&scene) == false || init_manager(&manager, av[1]) == false) {
        free_all(&scene, &manager);
        return (84);
    }
    while (sfRenderWindow_isOpen(manager.window))
        (*game_ptr[manager.state])(&scene, &manager);
    return (0);
}
