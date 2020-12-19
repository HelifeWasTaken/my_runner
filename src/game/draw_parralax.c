/*
** EPITECH PROJECT, 2020
** display_parralax.c
** File description:
** display_para
*/

#include <my_runner/scene.h>

void draw_parralax(scene_t *scene, game_manager_t *manager)
{
    sfTime time_struct = sfClock_getElapsedTime(manager->clock);
    float seconds = sfTime_asSeconds(time_struct);

    FOR_EACH_PARRALAX(i) {
        if (i) {
            sfSprite_setTextureRect(scene->parralax[i].layer,
                IRECT(seconds * (i * 30) + i * 30 + 5 + 120, 0, 512, 256));
            DRAW_SPRITE(manager->window, scene->parralax[i].layer);
        }
    }
}