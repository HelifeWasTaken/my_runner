/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** get_background
*/

#include <my_runner/scene.h>

bool get_volcano_background(scene_t *scene)
{
    scene->world.volcano.frame.frame = 0;
    scene->world.volcano.frame.elapsed = 0;
    scene->world.volcano.bg = my_calloc(sizeof(background_t), NB_BG_VOLCANO);
    scene->world.volcano.bg[0].texture = CREATE_TEXTURE(BG_VOLCANO_ONE);
    scene->world.volcano.bg[1].texture = CREATE_TEXTURE(BG_VOLCANO_TWO);
    scene->world.volcano.bg[2].texture = CREATE_TEXTURE(BG_VOLCANO_THREE);
    for (u_int8_t i = 0; i < NB_BG_VOLCANO; i++) {
        if (scene->world.volcano.bg[i].texture == NULL)
            return (false);
        SET_REPEATED_TEXTURE(scene->world.volcano.bg[i].texture);
        sfTexture_setSmooth(scene->world.volcano.bg[i].texture, sfTrue);
        scene->world.volcano.bg[i].layer = sfSprite_create();
        SET_TEXTURE(scene->world.volcano.bg[i].layer,
            scene->world.volcano.bg[i].texture);
        sfSprite_setScale(scene->world.volcano.bg[i].layer, VECF(3, 3));
    }
    return (true);
}
