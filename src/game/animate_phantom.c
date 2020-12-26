/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** animate_phantom
*/

#include <my_runner/runner.h>
#include <my_runner/scene.h>

void animate_phantom(scene_t *scene, game_manager_t *manager, size_t i)
{
    const sfIntRect phantom_frames[4] = {
        IRECT(162, 35, 30, 29), IRECT(128, 35, 30, 28),
        IRECT(93, 35, 32, 30), IRECT(59, 35, 31, 29)};
    animate_sprite(phantom_frames, scene->enemy[i].sprite,
            &scene->enemy[i].frame, manager->clock);
    scene->enemy[i].info.pos.y = GROUND_HEIGHT_PHANTOM;
    scene->enemy[i].info.pos.x -= 10;
}