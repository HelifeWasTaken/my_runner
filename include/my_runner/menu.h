/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** menu
*/

#pragma once

#ifndef __MY__RUNNER__MENU__H__
    #define __MY__RUNNER__MENU__H__
    #include <my_csfml.h>

    typedef struct menu {
        sfMusic *music;
        sfSprite *sprite_bg;
        sfTexture *texture_bg;
        sfSprite *sprite_logo;
        sfTexture *texture_logo;
        sfSprite *sprite_b1;
        sfTexture *texture_b1;
        sfSprite *sprite_b2;
        sfTexture *texture_b2;
        u_int8_t choice;
    } menu_t;

    #define BACKGROUND_MENU_ASSET       "./asset/menu/menu.png"
    #define LOGO_MENU_ASSET             "./asset/menu/logo.png"
    #define SOUND_MENU_ASSET            "./asset/menu/menu.ogg"
    #define PLAY_BUTTON_ASSET           "./asset/menu/play.png"
    #define QUIT_BUTTON_ASSET           "./asset/menu/quit.png"
#endif