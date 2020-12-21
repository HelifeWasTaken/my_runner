/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** player
*/

#pragma once

#ifndef __RUNNER__PLAYER__H__
    #define __RUNNER__PLAYER__H__
    #include <my_csfml.h>
    #include <my_runner/frames.h>

    typedef struct player {
        sfTexture *texture;
        frame_t frame;
        sfSprite *sprite;
        u_int8_t state;
        entity_t info;
    } player_t;

    enum {
        PLAYER_IDLE,
        PLAYER_JUMP,
        PLAYER_FALL
    };

    #define PLAYER_GROUND_HEIGHT    652

#endif
