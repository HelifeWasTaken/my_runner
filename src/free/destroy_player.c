/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** destroy_player
*/

#include <my_runner/free.h>

void destroy_player(scene_t *scene)
{
    if (scene->player.texture)
        sfTexture_destroy(scene->player.texture);
    if (scene->player.sprite)
        sfSprite_destroy(scene->player.sprite);
}