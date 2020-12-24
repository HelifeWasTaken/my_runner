/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** get_background
*/

#include <my_runner/scene.h>

bool get_background(scene_t *scene)
{
    scene->background_frame.frame = 0;
    scene->background_frame.elapsed = 0;
    scene->background = my_calloc(sizeof(g_background_t), NB_BACKGROUND);
    scene->background[0].texture = CREATE_TEXTURE(BACKGROUND_LAYER_ONE);
    scene->background[1].texture = CREATE_TEXTURE(BACKGROUND_LAYER_TWO);
    scene->background[2].texture = CREATE_TEXTURE(BACKGROUND_LAYER_THREE);
    for (u_int8_t i = 0; i < NB_BACKGROUND; i++) {
        if (scene->background[i].texture == NULL)
            return (false);
        SET_REPEATED_TEXTURE(scene->background[i].texture);
        sfTexture_setSmooth(scene->background[i].texture, sfTrue);
        scene->background[i].layer = sfSprite_create();
        SET_TEXTURE(scene->background[i].layer, scene->background[i].texture);
        sfSprite_setScale(scene->background[i].layer, VECF(3, 3));
    }
    return (true);
}