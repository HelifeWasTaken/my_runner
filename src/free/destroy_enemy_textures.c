/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** destroy_enemy_textures
*/

#include <my_runner/free.h>

void destroy_enemy_textures(scene_t *scene)
{
    if (!scene->enemy_texture)
        return;
    for (size_t i = 0; i < NB_ENEMY; i++) {
        if (scene->enemy_texture[i]) {
            sfTexture_destroy(scene->enemy_texture[i]);
        }
    }
    free(scene->enemy_texture);
}