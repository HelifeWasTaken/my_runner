/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** draw_volcano_world
*/

#include <my_runner/scene.h>
#include <my_runner/runner.h>

static void draw_parralax_volcano_world(scene_t *scene,
    game_manager_t *manager)
{
    sfTime time_struct = sfClock_getElapsedTime(manager->clock);
    float seconds = sfTime_asSeconds(time_struct);

    FOR_EACH_PARRALAX(i, NB_PARA_VOLCANO) {
        if (i) {
            sfSprite_setTextureRect(scene->world.volcano.para[i].layer,
                IRECT(seconds * (i * 30) + i * 30 + 5 + 120, 0, 512, 256));
            DRAW_SPRITE(manager->window, scene->world.volcano.para[i].layer);
        }
    }
}

static void draw_background_volcano_world(scene_t *scene,
    game_manager_t *manager)
{
    sfTime time_struct = sfClock_getElapsedTime(manager->clock);
    float seconds = sfTime_asSeconds(time_struct);

    if (seconds >
        scene->world.volcano.frame.elapsed + TIME_SHIFT_BACKGROUND) {
        scene->world.volcano.frame.elapsed = seconds;
        (scene->world.volcano.frame.frame)++;
        if (scene->world.volcano.frame.frame > 2)
            scene->world.volcano.frame.frame = 0;
    }
    sfSprite_setTextureRect(
            scene->world.volcano.bg[scene->world.volcano.frame.frame].layer,
            IRECT(seconds * 20, 0, 512, 256));
    DRAW_SPRITE(manager->window,
        scene->world.volcano.bg[scene->world.volcano.frame.frame].layer);
}

void draw_volcano(scene_t *scene, game_manager_t *manager)
{
    draw_background_volcano_world(scene, manager);
    draw_parralax_volcano_world(scene, manager);
}