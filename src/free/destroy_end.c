/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** destroy_end
*/

#include <my_runner/scene.h>

void destroy_end(scene_t *scene)
{
    if (scene->end.music)
        sfMusic_destroy(scene->end.music);
    if (scene->end.texture_bg)
        sfTexture_destroy(scene->end.texture_bg);
    if (scene->end.sprite_bg)
        sfSprite_destroy(scene->end.sprite_bg);
}