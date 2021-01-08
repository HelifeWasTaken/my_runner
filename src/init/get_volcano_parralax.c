/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** get_volcano_parralax
*/

#include <my_runner/scene.h>

bool get_volcano_parralax(scene_t *scene)
{
    scene->world.volcano.para = my_calloc(sizeof(parralax_t), NB_PARA_VOLCANO);
    scene->world.volcano.para[0].texture = CREATE_TEXTURE(PARA_VOLCANO_ONE);
    scene->world.volcano.para[1].texture = CREATE_TEXTURE(PARA_VOLCANO_TWO);
    scene->world.volcano.para[2].texture = CREATE_TEXTURE(PARA_VOLCANO_THREE);
    scene->world.volcano.para[3].texture = CREATE_TEXTURE(PARA_VOLCANO_FOUR);
    scene->world.volcano.para[4].texture = CREATE_TEXTURE(PARA_VOLCANO_FIVE);
    scene->world.volcano.para[5].texture = CREATE_TEXTURE(PARA_VOLCANO_SIX);
    scene->world.volcano.para[6].texture = CREATE_TEXTURE(PARA_VOLCANO_SEVEN);
    scene->world.volcano.para[7].texture = CREATE_TEXTURE(PARA_VOLCANO_HEIGHT);
    FOR_EACH_PARRALAX(i, NB_PARA_VOLCANO) {
        if (scene->world.volcano.para[i].texture == NULL)
            return (false);
        SET_REPEATED_TEXTURE(scene->world.volcano.para[i].texture);
        sfTexture_setSmooth(scene->world.volcano.para[i].texture, sfTrue);
        scene->world.volcano.para[i].layer = sfSprite_create();
        SET_TEXTURE(scene->world.volcano.para[i].layer,
            scene->world.volcano.para[i].texture);
        sfSprite_setScale(scene->world.volcano.para[i].layer, VECF(3, 3));
    }
    return (true);
}