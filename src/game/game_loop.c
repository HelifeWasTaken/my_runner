/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** game_loop
*/

#include <my_runner/scene.h>
#include <my_runner/runner.h>
#include <my_runner/free.h>

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

static void map_game_loop(scene_t *scene, game_manager_t *manager)
{
    scene->menu.trigger_error = false;
    scene->world.choice = change_world(scene->world.choice);
    if (!prepare_map_positions(scene, manager->map, manager)) {
        scene->menu.trigger_error = true;
        manager->state = MENU;
        return;
    }
    manager->score = 0;
    sfMusic_stop(scene->menu.music);
    sfMusic_play(scene->music.game);
    while (sfRenderWindow_isOpen(manager->window) && manager->state == GAME) {
        check_game_event(scene, manager);
        draw_all_game(scene, manager);
        if (manager->state != END && (scene->player.info.state == ON_GROUND ||
            scene->player.info.state == JUMPING ||
            scene->player.info.state == FALLING))
            manager->score += 1;
    }
    sfMusic_stop(scene->music.game);
}

static void infinity_game_loop(scene_t *scene, game_manager_t *manager)
{
    scene->world.choice = change_world(scene->world.choice);
    prepare_infinity_position(scene, manager);
    manager->score = 0;
    sfMusic_stop(scene->menu.music);
    sfMusic_play(scene->music.game);
    while (sfRenderWindow_isOpen(manager->window) && manager->state == GAME) {
        check_game_event(scene, manager);
        draw_all_game(scene, manager);
        if (manager->state != END && (scene->player.info.state == ON_GROUND ||
            scene->player.info.state == JUMPING ||
            scene->player.info.state == FALLING))
            manager->score += 1;
    }
    sfMusic_stop(scene->music.game);
}

void game_loop(scene_t *scene, game_manager_t *manager)
{
    if (manager->infinty_enabled)
        infinity_game_loop(scene, manager);
    else
        map_game_loop(scene, manager);
}
