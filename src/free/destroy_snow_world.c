/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** destroy_snow_world
*/

#include <my_runner/scene.h>

void destroy_snow_world(scene_t *scene)
{
    if (scene->world.snow.para == NULL)
        return;
    for (size_t i = 0; i < NB_PARA_SNOW; i++) {
        if (scene->world.snow.para[i].layer)
            sfSprite_destroy(scene->world.snow.para[i].layer);
        if (scene->world.snow.para[i].texture)
            sfTexture_destroy(scene->world.snow.para[i].texture);
    }
    free(scene->world.snow.para);
}