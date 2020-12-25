/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** get_parralax_textures
*/

#include <my_runner/scene.h>

bool get_parralax_texture(scene_t *scene)
{
    return (get_volcano_parralax(scene) && get_forest_parralax(scene) &&
        get_snow_parralax(scene));
}