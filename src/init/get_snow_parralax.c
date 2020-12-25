/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** get_snow_parralax
*/

#include <my_runner/scene.h>

static void set_snow_parralax_sprites(scene_t *scene, size_t i)
{
    SET_REPEATED_TEXTURE(scene->world.snow.para[i].texture);
    sfTexture_setSmooth(scene->world.snow.para[i].texture, sfTrue);
    scene->world.snow.para[i].layer = sfSprite_create();
    SET_TEXTURE(scene->world.snow.para[i].layer,
                scene->world.snow.para[i].texture);
    sfSprite_setScale(scene->world.snow.para[i].layer, VECF(3, 3));
}

bool get_snow_parralax(scene_t *scene)
{
    scene->world.snow.para = my_calloc(sizeof(parralax_t), NB_PARA_SNOW);
    scene->world.snow.para[0].texture = CREATE_TEXTURE(PARA_SNOW_ONE);
    scene->world.snow.para[1].texture = CREATE_TEXTURE(PARA_SNOW_TWO);
    scene->world.snow.para[2].texture = CREATE_TEXTURE(PARA_SNOW_THREE);
    scene->world.snow.para[3].texture = CREATE_TEXTURE(PARA_SNOW_FOUR);
    scene->world.snow.para[4].texture = CREATE_TEXTURE(PARA_SNOW_FIVE);
    scene->world.snow.para[5].texture = CREATE_TEXTURE(PARA_SNOW_SIX);
    scene->world.snow.para[6].texture = CREATE_TEXTURE(PARA_SNOW_SEVEN);
    scene->world.snow.para[7].texture = CREATE_TEXTURE(PARA_SNOW_HEIGHT);
    scene->world.snow.para[8].texture = CREATE_TEXTURE(PARA_SNOW_NINE);
    FOR_EACH_PARRALAX(i, NB_PARA_SNOW) {
        if (scene->world.snow.para[i].texture == NULL)
            return (false);
        set_snow_parralax_sprites(scene, i);
    }
    return (true);
}