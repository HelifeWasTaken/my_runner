/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** get_player
*/

#include <my_runner/scene.h>

void reset_player(scene_t *scene)
{
    scene->player.frame = FRAME_SET(0, 6, TIME_SHIFT_PLAYER_IDLE);
    scene->player.info = (entity_t){VECF(0.04f, 1), 5, VECF(0, 0),
        MIN_MAX_FLOAT(PLAYER_GROUND_HEIGHT, PLAYER_GROUND_HEIGHT - 45),
        VECF(-100, PLAYER_GROUND_HEIGHT), INIT};
    sfSprite_setTextureRect(scene->player.sprite, IRECT(0, 0, 0, 0));
}

bool get_player(scene_t *scene)
{
    scene->player.texture = my_calloc(sizeof(sfTexture *), NB_PLAYER_SPRITES);
    scene->player.texture[0] = CREATE_TEXTURE(PLAYER_SPRITE_1);
    scene->player.texture[1] = CREATE_TEXTURE(PLAYER_SPRITE_2);
    scene->player.texture[2] = CREATE_TEXTURE(PLAYER_SPRITE_3);
    scene->player.texture[3] = CREATE_TEXTURE(PLAYER_SPRITE_4);
    scene->player.texture[4] = CREATE_TEXTURE(PLAYER_SPRITE_5);
    for (int i = 0; i < NB_PLAYER_SPRITES; i++) {
        if (scene->player.texture[i] == NULL)
            return (false);
    }
    scene->player.sprite = sfSprite_create();
    SET_TEXTURE(scene->player.sprite, scene->player.texture[0]);
    sfSprite_setScale(scene->player.sprite, VECF(4, 4));
    scene->player.player_type = 1;
    reset_player(scene);
    return (true);
}
