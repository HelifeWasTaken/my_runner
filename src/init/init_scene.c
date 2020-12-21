/*
** EPITECH PROJECT, 2020
** init_scene.c
** File description:
** scene
*/

#include <my_runner/scene.h>

static bool load_enemy_textures(scene_t *scene)
{
    scene->enemy_texture = malloc(sizeof(sfTexture *) * NB_ENEMY);
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

static bool get_parralax_texture(scene_t *scene)
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

bool get_backgrounds(scene_t *scene)
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

static bool get_player(scene_t *scene)
{
    scene->player.state = PLAYER_IDLE;
    scene->player.frame = FRAME_SET(0, 8, TIME_SHIFT_PLAYER_IDLE);
    scene->player.texture = CREATE_TEXTURE(PLAYER_SPRITE);
    if (scene->player.texture == NULL)
        return (false);
    scene->player.sprite = sfSprite_create();
    SET_TEXTURE(scene->player.sprite, scene->player.texture);
    sfSprite_setScale(scene->player.sprite, VECF(4, 4));
    scene->player.info = (entity_t){VECF(0.1f, 0.3f), 5, VECF(0, 0),
        MIN_MAX_FLOAT(PLAYER_GROUND_HEIGHT, PLAYER_GROUND_HEIGHT - 30),
        VECF(50, PLAYER_GROUND_HEIGHT), ON_GROUND, ZERO_COL};
    return (true);
}

bool init_scene(scene_t *scene, char **av __attribute__((unused)))
{
    if (!get_parralax_texture(scene))
        return (false);
    if (!get_backgrounds(scene))
        return (false);
    if (!get_player(scene))
        return (false);
    if (!load_enemy_textures(scene))
        return (false);
    if (!map_loader(scene, av[1]))
        return (false);
    return (true);
}
