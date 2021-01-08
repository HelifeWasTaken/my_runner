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

    ///////////////////////// PLAYER ///////////////////////////

    #define NB_PLAYER_SPRITES           5

    #define PLAYER_SPRITE_1             "asset/vania/herochar/sheet.png"
    #define PLAYER_SPRITE_2             "asset/vania/herochar/sheet2.png"
    #define PLAYER_SPRITE_3             "asset/vania/herochar/sheet3.png"
    #define PLAYER_SPRITE_4             "asset/vania/herochar/sheet4.png"
    #define PLAYER_SPRITE_5             "asset/vania/herochar/sheet5.png"

    #define TIME_SHIFT_PLAYER_IDLE      0.07f
    #define TIME_SHIFT_PLAYER_JUMP      0.15f

    /////////////////////// BACKGROUND /////////////////////////

    #define TIME_SHIFT_BACKGROUND   0.18f

    //////////////////////// MUSHROOM //////////////////////////

    #define MUSHROOM_TIME_SHIFT     0.1f

    //////////////////////// SLIME ////////////////////////////

    #define SLIME_TIME_SHIFT        0.1f

    //////////////////////// NINJA ////////////////////////////

    #define NINJA_TIME_SHIFT        0.1f

    /////////////////////// PHANTOM ///////////////////////////

    #define PHANTOM_TIME_SHIFT      0.1f

#endif
