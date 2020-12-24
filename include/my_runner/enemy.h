/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** enemy
*/

#pragma once

#ifndef __RUNNER__ENEMY__H__
    #define __RUNNER__ENEMY__H__

    enum {
        FLY_ENEMY,
        GOBLIN,
        MUSHROOM,
        SLIME
    };

    enum {
        IDLE,
        ACTION,
    };

    typedef struct enemy_st {
        frame_t frame;
        sfSprite *sprite;
        int8_t enemy_id;
        u_int8_t state;
        entity_t info;
    } enemy_t;

    #define NB_ENEMY                4
    #define INF_ARR_ENEMY_SIZE      30
    #define FLY_SPRITE_SHEET        "asset/vania/enemy/fly/sheet.png"
    #define MUSHROOM_SPRITE_SHEET   "asset/vania/enemy/mushroom/sheet.png"
    #define GOBLIN_SPRITE_SHEET     "asset/vania/enemy/goblin/sheet.png"
    #define SLIME_SPRITE_SHEET      "asset/vania/enemy/slime/sheet.png"

    #define GROUND_HEIGHT_MUSHROOM  677
    #define GROUND_HEIGHT_SLIME     691
#endif