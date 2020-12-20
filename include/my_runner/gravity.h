/*
** EPITECH PROJECT, 2020
** gravity.h
** File description:
** handle_gravity
*/

#pragma once

#ifndef __MY_CSFML_GRAVITY__H__
    #define __MY_CSFML_GRAVITY__H__
    #include <my_csfml.h>
    enum {
        ON_GROUND,
        JUMPING,
        FALLING
    };

    typedef struct {
        sfVector2f momentum;
        float max_velocity;
        sfVector2f vel;
        float min_h;
        float max_h;
        sfVector2f entity_position;
        u_int8_t state;
    } gravity_t;
    bool handle_gravity(gravity_t *info);
#endif
