/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** draw_menu_cursor
*/

#include <my_runner/runner.h>
#include <my_runner/scene.h>

void draw_menu_cursor(scene_t *scene, game_manager_t *manager)
{
    const sfIntRect player_idle_frames[6] = {
        IRECT(1, 18, 12, 14), IRECT(16, 17, 13, 13), IRECT(32, 17, 13, 15),
        IRECT(49, 17, 12, 15), IRECT(65, 17, 12, 13), IRECT(81, 18, 12, 14)};

    if (scene->menu.choice == GAME_CHOICE) {
        sfSprite_setPosition(scene->player.sprite,
            VECF(WIN_W / 2 - 170, WIN_H - 400));
    } else {
        sfSprite_setPosition(scene->player.sprite,
            VECF(WIN_W / 2 - 150, WIN_H - 300));
    }
    animate_sprite(player_idle_frames, scene->player.sprite,
        &scene->player.frame, manager->clock);
    DRAW_SPRITE(manager->window, scene->player.sprite);
}

