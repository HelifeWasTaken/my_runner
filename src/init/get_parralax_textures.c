/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** get_parralax_textures
*/

#include <my_runner/scene.h>

bool get_parralax_texture(scene_t *scene)
{
    scene->parralax = my_calloc(sizeof(parralax_t), NB_PARRALAX);
    scene->parralax[0].texture = CREATE_TEXTURE(PARRALAX_LAYER_ONE);
    scene->parralax[1].texture = CREATE_TEXTURE(PARRALAX_LAYER_TWO);
    scene->parralax[2].texture = CREATE_TEXTURE(PARRALAX_LAYER_THREE);
    scene->parralax[3].texture = CREATE_TEXTURE(PARRALAX_LAYER_FOUR);
    scene->parralax[4].texture = CREATE_TEXTURE(PARRALAX_LAYER_FIVE);
    scene->parralax[5].texture = CREATE_TEXTURE(PARRALAX_LAYER_SIX);
    scene->parralax[6].texture = CREATE_TEXTURE(PARRALAX_LAYER_SEVEN);
    scene->parralax[7].texture = CREATE_TEXTURE(PARRALAX_LAYER_HEIGHT);
    for (u_int8_t i = 0; i < NB_PARRALAX; i++) {
        if (scene->parralax[i].texture == NULL)
            return (false);
        SET_REPEATED_TEXTURE(scene->parralax[i].texture);
        sfTexture_setSmooth(scene->parralax[i].texture, sfTrue);
        scene->parralax[i].layer = sfSprite_create();
        SET_TEXTURE(scene->parralax[i].layer, scene->parralax[i].texture);
        sfSprite_setScale(scene->parralax[i].layer, VECF(3, 3));
    }
    return (true);
}