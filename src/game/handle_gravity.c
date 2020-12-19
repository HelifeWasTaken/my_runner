/*
** EPITECH PROJECT, 2020
** handle_gravity.c
** File description:
** handle_gravity
*/

#include <my_runner/gravity.h>

bool handle_gravity(gravity_t *info)
{
    if (info->entity_position.y >= info->min_h && info->state == FALLING) {
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
    if (info->entity_position.y <= info->max_h)
        info->state = FALLING;
    info->entity_position.y += info->vel.y;
    info->entity_position.x += info->vel.x;
    return (false);
}