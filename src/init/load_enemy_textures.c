/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** load_enemy_textures
*/

#include <my_runner/scene.h>

bool load_enemy_textures(scene_t *scene)
{
    scene->enemy_texture = my_calloc(sizeof(sfTexture *), NB_ENEMY);
    scene->enemy_texture[0] = CREATE_TEXTURE(FLY_SPRITE_SHEET);
    scene->enemy_texture[1] = CREATE_TEXTURE(GOBLIN_SPRITE_SHEET);
    scene->enemy_texture[2] = CREATE_TEXTURE(MUSHROOM_SPRITE_SHEET);
    scene->enemy_texture[3] = CREATE_TEXTURE(SLIME_SPRITE_SHEET);
    for (u_int8_t i = 0; i < NB_ENEMY; i++) {
        if (scene->enemy_texture[i] == NULL)
            return (false);
    }
    return (true);
}