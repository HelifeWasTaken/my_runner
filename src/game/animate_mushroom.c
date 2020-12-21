/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** animate_mushroom
*/

#include <my_runner/scene.h>


void animate_mushroom(scene_t *scene, game_manager_t *manager, size_t i)
{
    const sfIntRect mushroom_frames[8] = {
        IRECT(113, 0, 14, 15), IRECT(97, 0, 14, 16), IRECT(82, 0, 12, 16),
        IRECT(65, 2, 14, 14), IRECT(49, 0, 14, 16), IRECT(33, 0, 14, 16),
        IRECT(18, 0, 12, 16), IRECT(1, 2, 14, 14)
    };

    animate_sprite(mushroom_frames, scene->enemy[i].sprite,
            &scene->enemy[i].frame, manager->clock);
    scene->enemy[i].info.pos.y = GROUND_HEIGHT_MUSHROOM;
    scene->enemy[i].info.pos.x -= 10;
}
