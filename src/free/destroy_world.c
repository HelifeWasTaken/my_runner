/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** destroy_background
*/

#include <my_runner/free.h>

void destroy_world(scene_t *scene)
{
    destroy_snow_world(scene);
    destroy_volcano_world(scene);
    destroy_forest_world(scene);
}