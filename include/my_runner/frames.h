/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** frames
*/

#pragma once

#ifndef __RUNNER__FRAMES__H__
    #define __RUNNER__FRAMES__H__
    #include <my_csfml.h>

    typedef struct frame_manager {
        u_int8_t frame;
        float elapsed_time;
    } frame_t;

    /////////////////////////// PLAYER /////////////////////////////

    enum {
        PLAYER_FRAME_ONE,
        PLAYER_FRAME_TWO,
        PLAYER_FRAME_THREE,
        PLAYER_FRAME_FOUE,
        PLAYER_FRAME_FIVE,
        PLAYER_FRAME_SIX,
        PLAYER_FRAME_SEVEN,
        PLAYER_FRAME_HEIGHT
    };

    #define PLAYER_SPRITE           "asset/png/characters/01.png"
    #define TIME_SHIFT_PLAYER_IDLE  0.1f
    #define TIME_SHIFT_PLAYER_JUMP  0.2f

    //////////////////////// BACKGROUND //////////////////////////

    enum {
        BACKGROUND_FRAME_ONE,
        BACKGROUND_FRAME_TWO,
        BACKGROUND_FRAME_THREE
    };

    #define NB_BACKGROUND           3
    #define BACKGROUND_LAYER_ONE    "asset/png/night/volcano/anim01.png"
    #define BACKGROUND_LAYER_TWO    "asset/png/night/volcano/anim02.png"
    #define BACKGROUND_LAYER_THREE  "asset/png/night/volcano/anim03.png"
    #define TIME_SHIFT_BACKGROUND   0.18f

    //////////////////////// MUSHROOM //////////////////////////

    enum {
        MUSHROOM_FRAME_ONE,
        MUSHROOM_FRAME_TWO,
        MUSHROOM_FRAME_THREE,
        MUSHROOM_FRAME_FOUE,
        MUSHROOM_FRAME_FIVE,
        MUSHROOM_FRAME_SIX,
        MUSHROOM_FRAME_SEVEN,
        MUSHROOM_FRAME_HEIGHT
    };

    #define MUSHROOM_TIME_SHIFT     0.1f

    //////////////////////// SLIME ////////////////////////////

    enum {
        SLIME_FRAME_ONE,
        SLIME_FRAME_TWO,
        SLIME_FRAME_THREE,
        SLIME_FRAME_FOUR,
        SLIME_FRAME_FIVE,
        SLIME_FRAME_SIX,
        SLIME_FRAME_SEVEN,
        SLIME_FRAME_HEIGHT,
        SLIME_FRAME_NINE,
        SLIME_FRAME_TEN,
        SLIME_FRAME_ELEVEN,
        SLIME_FRAME_TWELVE,
        SLIME_FRAME_THIRTEEN,
        SLIME_FRAME_FOURTEEN,
        SLIME_FRAME_FIFTEEN
    };

    #define SLIME_TIME_SHIFT        0.1f
#endif