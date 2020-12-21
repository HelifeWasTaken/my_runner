/*
** EPITECH PROJECT, 2020
** handle_gravity.c
** File description:
** handle_gravity
*/

#include <my_csfml.h>

bool handle_gravity(entity_t *info)
{
    if (info->pos.y >= info->edge.min && info->state == FALLING) {
        info->state = ON_GROUND;
        info->vel.y = 0;
        info->vel.x = 0;
        return (true);
    }
    if (info->state == JUMPING) {
        info->vel.y -= info->momentum.y;
        info->vel.x += info->momentum.x;
    }
    else {
        info->vel.y += info->momentum.y;
        info->vel.x += info->momentum.x / 2;
    }
    if (info->pos.y <= info->edge.max)
        info->state = FALLING;
    info->pos.y += info->vel.y;
    info->pos.x += info->vel.x;
    return (false);
}
