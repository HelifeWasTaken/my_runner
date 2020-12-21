/*
** EPITECH PROJECT, 2020
** draw_background.c
** File description:
** draw_background
*/

#include <my_runner/scene.h>
#include <my_runner/runner.h>

void draw_background(scene_t *scene, game_manager_t *manager)
{
    sfTime time_struct = sfClock_getElapsedTime(manager->clock);
    float seconds = sfTime_asSeconds(time_struct);

    if (seconds >
        scene->background_frame.elapsed + TIME_SHIFT_BACKGROUND) {
        scene->background_frame.elapsed = seconds;
        (scene->background_frame.frame)++;
        if (scene->background_frame.frame > 2)
            scene->background_frame.frame = 0;
    }
    sfSprite_setTextureRect(
            scene->background[scene->background_frame.frame].layer,
            IRECT(seconds * 20, 0, 512, 256));
    DRAW_SPRITE(manager->window,
        scene->background[scene->background_frame.frame].layer);
}