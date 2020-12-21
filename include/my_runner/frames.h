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

    /////////////////////////// PLAYER /////////////////////////////

    #define PLAYER_SPRITE           "asset/png/characters/01.png"
    #define TIME_SHIFT_PLAYER_IDLE  0.1f
    #define TIME_SHIFT_PLAYER_JUMP  0.2f

    //////////////////////// BACKGROUND //////////////////////////

    #define NB_BACKGROUND           3
    #define BACKGROUND_LAYER_ONE    "asset/png/night/volcano/anim01.png"
    #define BACKGROUND_LAYER_TWO    "asset/png/night/volcano/anim02.png"
    #define BACKGROUND_LAYER_THREE  "asset/png/night/volcano/anim03.png"
    #define TIME_SHIFT_BACKGROUND   0.18f

    //////////////////////// MUSHROOM //////////////////////////


    #define MUSHROOM_TIME_SHIFT     0.1f

    //////////////////////// SLIME ////////////////////////////

    #define SLIME_TIME_SHIFT        0.1f
#endif
