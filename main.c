/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <my_runner/runner.h>
#include <my_runner/scene.h>
#include <my_stdio.h>

static void show_help(void)
{
    my_printf(YELLOW"MY_RUNNER\n\n");
    my_printf(BLUE"\tTo launch it use :" GREEN" ./my_runner [map]\n");
    my_printf(BLUE"\tTo see this help use:" GREEN" ./my_runner -h\n");
    my_printf(PURPLE"\nDESCRIPTION:\n\n");
    my_printf(CYAN"\t\tTODO\n\n");
    my_printf(RED"Mattis DALLEAU\n"DEFAULT);
}

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
        show_help();
        return (0);
    }
    my_dprintf(2, RED"my_runner :"
                YELLOW"\n\tYou have given a wrong argument !\n"
                CYAN"You can try :" GREEN"\n\t./my_runner -h to"
                " show the help\n"DEFAULT);
    return (-1);
}

void prepare_map_positions(scene_t *scene)
{
    sfVector2f pos = VECF(3000, 0);

    srand(time(NULL));
    for (size_t i = 0; scene->enemy[i].enemy_id != -2; i++) {
        pos.x += 200;
        if (scene->enemy[i].enemy_id == -1)
            continue;
        scene->enemy[i].info.entity_position.x = pos.x;
        sfSprite_setPosition(scene->enemy[i].sprite,
            scene->enemy[i].info.entity_position);
    }
}

int main(int ac, char **av)
{
    int usage_return = 0;
    game_manager_t manager;
    scene_t scene = {0};

    usage_return = usage(ac, av);
    if (usage_return == 0)
        return (0);
    if (usage_return == -1)
        return (84);
    if (init_scene(&scene, av) == false)
        return (84);
    manager.window = CREATE_WINDOW(WIN_MODE, WINDOW_NAME);
    SET_FRAME_LIMIT(manager.window, 60);
    manager.clock = sfClock_create();
    manager.score = 0;
    prepare_map_positions(&scene);
    while (sfRenderWindow_isOpen(manager.window)) {
        while (CHECK_WINDOW_EVENT(manager.window, manager.event)) {
            if (manager.event.type == sfEvtClosed)
                CLOSE_WINDOW(manager.window);
            if (sfKeyboard_isKeyPressed(sfKeySpace) &&
                scene.player.info.state == ON_GROUND) {
                scene.player.frame.frame = PLAYER_FRAME_ONE;
                scene.player.info.state = JUMPING;
            }
        }
        draw_all_game(&scene, &manager);
        manager.score += 1;
    }
    return (0);
}