/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** destroy_player
*/

#include <my_runner/free.h>

static void free_player_textures(scene_t *scene)
{
    for (int i = 0; i < NB_PLAYER_SPRITES; i++) {
        if (scene->player.texture[i] == NULL)
            sfTexture_destroy(scene->player.texture[i]);
    }
}

void destroy_player(scene_t *scene)
{
    if (scene->player.texture) {
        free_player_textures(scene);
        free(scene->player.texture);
    }
    if (scene->player.sprite)
        sfSprite_destroy(scene->player.sprite);
}