/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** background
*/

#pragma once

#ifndef __RUNNER___BACKGROUND__H__
    #define __RUNNER__BACKGROUND__H__
    #include <my_csfml.h>

    typedef struct parralax {
        sfSprite *layer;
        sfTexture *texture;
    } parralax_t;

    typedef struct game_background {
        sfSprite *layer;
        sfTexture *texture;
    } g_background_t;

#endif