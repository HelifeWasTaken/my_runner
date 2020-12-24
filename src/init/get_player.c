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
    scene->player.info = (entity_t){VECF(0.08f, 0.4f), 5, VECF(0, 0),
        MIN_MAX_FLOAT(PLAYER_GROUND_HEIGHT, PLAYER_GROUND_HEIGHT - 30),
        VECF(50, PLAYER_GROUND_HEIGHT), ON_GROUND};
    sfSprite_setTextureRect(scene->player.sprite, IRECT(0, 0, 0, 0));
}

bool get_player(scene_t *scene)
{
    scene->player.texture = CREATE_TEXTURE(PLAYER_SPRITE);
    if (scene->player.texture == NULL)
        return (false);
    scene->player.sprite = sfSprite_create();
    SET_TEXTURE(scene->player.sprite, scene->player.texture);
    sfSprite_setScale(scene->player.sprite, VECF(4, 4));
    reset_player(scene);
    return (true);
}
