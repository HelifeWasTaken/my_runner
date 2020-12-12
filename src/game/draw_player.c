/*
** EPITECH PROJECT, 2020
** draw_player.c
** File description:
** draw_the_player
*/

#include <my_runner.h>

static const sfIntRect player_sprite_pos[8] = {
    IRECT(12, 45, 12, 17),
    IRECT(48, 45, 12, 17),
    IRECT(84, 45, 12, 17),
    IRECT(12, 82, 12, 17),
    IRECT(48, 82, 12, 17),
    IRECT(84, 82, 12, 17),
    IRECT(12, 117, 12, 17),
    IRECT(48, 117, 12, 17)
};

void draw_player(scene_t *scene, game_manager_t *manager)
{
    sfTime time_struct = sfClock_getElapsedTime(manager->clock);
    float seconds = sfTime_asSeconds(time_struct);

    if (seconds > scene->player_frame.elapsed_time + TIME_SHIFT_PLAYER) {
        scene->player_frame.elapsed_time = seconds;
        (scene->player_frame.frame)++;
        if (scene->player_frame.frame > PLAYER_FRAME_HEIGHT)
            scene->player_frame.frame = PLAYER_FRAME_ONE;
    }
    sfSprite_setTextureRect(scene->player.sprite,
        player_sprite_pos[scene->player_frame.frame]);
    sfSprite_setPosition(scene->player.sprite, scene->player.pos);
    DRAW_SPRITE(manager->window, scene->player.sprite);
}
