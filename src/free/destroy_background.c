/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** destroy_background
*/

#include <my_runner/free.h>

void destroy_background(scene_t *scene)
{
    for (size_t i = 0; i < NB_PARRALAX; i++) {
        if (scene->parralax[i].layer)
            sfSprite_destroy(scene->parralax[i].layer);
        if (scene->parralax[i].texture)
            sfTexture_destroy(scene->parralax[i].texture);
    }
    for (size_t i = 0; i < NB_BACKGROUND; i++) {
        if (scene->background[i].layer)
            sfSprite_destroy(scene->background[i].layer);
        if (scene->background[i].texture)
            sfTexture_destroy(scene->background[i].texture);
    }
}

