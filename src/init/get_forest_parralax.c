/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** get_forest_parralax
*/

#include <my_runner/scene.h>

bool get_forest_parralax(scene_t *scene)
{
    scene->world.forest.para = my_calloc(sizeof(parralax_t), NB_PARA_FOREST);
    scene->world.forest.para[0].texture = CREATE_TEXTURE(PARA_FOREST_ONE);
    scene->world.forest.para[1].texture = CREATE_TEXTURE(PARA_FOREST_TWO);
    scene->world.forest.para[2].texture = CREATE_TEXTURE(PARA_FOREST_THREE);
    scene->world.forest.para[3].texture = CREATE_TEXTURE(PARA_FOREST_FOUR);
    scene->world.forest.para[4].texture = CREATE_TEXTURE(PARA_FOREST_FIVE);
    scene->world.forest.para[5].texture = CREATE_TEXTURE(PARA_FOREST_SIX);
    FOR_EACH_PARRALAX(i, NB_PARA_FOREST) {
        if (scene->world.forest.para[i].texture == NULL)
            return (false);
        SET_REPEATED_TEXTURE(scene->world.forest.para[i].texture);
        sfTexture_setSmooth(scene->world.forest.para[i].texture, sfTrue);
        scene->world.forest.para[i].layer = sfSprite_create();
        SET_TEXTURE(scene->world.forest.para[i].layer,
            scene->world.forest.para[i].texture);
        sfSprite_setScale(scene->world.forest.para[i].layer, VECF(3, 3));
    }
    return (true);
}