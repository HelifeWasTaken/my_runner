/*
** EPITECH PROJECT, 2020
** init_scene.c
** File description:
** scene
*/

#include <my_runner.h>

static void get_parralax_texture(scene_t *scene)
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
        SET_REPEATED_TEXTURE(scene->parralax[i].texture);
        sfTexture_setSmooth(scene->parralax[i].texture, sfTrue);
        scene->parralax[i].layer = sfSprite_create();
        SET_TEXTURE(scene->parralax[i].layer, scene->parralax[i].texture);
        sfSprite_setScale(scene->parralax[i].layer, VECF(3, 3));
    }
}

void get_backgrounds(scene_t *scene)
{
    scene->background_frame.frame = BACKGROUND_FRAME_ONE;
    scene->background_frame.elapsed_time = 0;
    scene->background = my_calloc(sizeof(g_background_t), NB_BACKGROUND);
    scene->background[0].texture = CREATE_TEXTURE(BACKGROUND_LAYER_ONE);
    scene->background[1].texture = CREATE_TEXTURE(BACKGROUND_LAYER_TWO);
    scene->background[2].texture = CREATE_TEXTURE(BACKGROUND_LAYER_THREE);
    for (u_int8_t i = 0; i < NB_BACKGROUND; i++) {
        SET_REPEATED_TEXTURE(scene->background[i].texture);
        sfTexture_setSmooth(scene->background[i].texture, sfTrue);
        scene->background[i].layer = sfSprite_create();
        SET_TEXTURE(scene->background[i].layer, scene->background[i].texture);
        sfSprite_setScale(scene->background[i].layer, VECF(3, 3));
    }
}

void get_player(scene_t *scene)
{
    scene->player_frame.frame = PLAYER_FRAME_ONE;
    scene->player_frame.elapsed_time = 0;
    scene->player.texture = CREATE_TEXTURE(PLAYER_SPRITE);
    scene->player.sprite = sfSprite_create();
    SET_TEXTURE(scene->player.sprite, scene->player.texture);
    sfSprite_setScale(scene->player.sprite, VECF(4, 4));
    scene->player.pos = VECF(50, GROUND_HEIGHT);
}

scene_t init_scene(void)
{
    scene_t scene;

    get_parralax_texture(&scene);
    get_backgrounds(&scene);
    get_player(&scene);
    return (scene);
}
