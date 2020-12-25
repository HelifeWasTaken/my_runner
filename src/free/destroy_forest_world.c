/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** destroy_forest_world
*/

#include <my_runner/scene.h>

void destroy_forest_world(scene_t *scene)
{
    if (scene->world.forest.para == NULL)
        return;
    for (size_t i = 0; i < NB_PARA_FOREST; i++) {
        if (scene->world.forest.para[i].layer)
            sfSprite_destroy(scene->world.forest.para[i].layer);
        if (scene->world.forest.para[i].texture)
            sfTexture_destroy(scene->world.forest.para[i].texture);
    }
    free(scene->world.forest.para);
}