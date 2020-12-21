/*
** EPITECH PROJECT, 2020
** animate_sprite.c
** File description:
** animate
*/

#include <my_csfml.h>
#include <my_runner/frames.h>

void animate_sprite(const sfIntRect *rect, sfSprite *sprite, frame_t *frame,
        sfClock *clock)
{
    sfTime time_struct  = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asSeconds(time_struct);

    if (seconds > frame->elapsed + frame->offset) {
        if (frame->frame == frame->frame_max - 1)
            frame->frame = 0;
        sfSprite_setTextureRect(sprite, rect[frame->frame]);
        frame->frame++;
        frame->elapsed = seconds;
    }
}
