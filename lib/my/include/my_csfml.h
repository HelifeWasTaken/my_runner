/*
** EPITECH PROJECT, 2020
** my_csfml
** File description:
** header_file
*/

#pragma once

#ifndef __MY_CSFML__H__
    #define __MY_CSFML__H__
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <stdlib.h>
    #include <math.h>
    #include <time.h>
    #include <my_stdlib.h>
    #include <my_str.h>
    #include <my_stdio.h>
    #include <my_math.h>
    sfSprite *create_static_image(char const *filename);
    sfBool check_if_mouse_over_sprite(sfSprite *sprite, sfVector2i mouse_pos);
    #define CREATE_WINDOW(w, n) sfRenderWindow_create(w, n, sfClose, NULL)
    #define SET_FRAME_LIMIT(win, fps) sfRenderWindow_setFramerateLimit(win, fps)
    #define CLOSE_WINDOW(win) sfRenderWindow_close(win)
    #define CHECK_WINDOW_EVENT(win, evt) sfRenderWindow_pollEvent(win, &evt)
    #define CREATE_TEXTURE(file) sfTexture_createFromFile(file, NULL)
    #define SET_TEXTURE(sp, texture) sfSprite_setTexture(sp, texture, sfFalse)
    #define SET_REPEATED_TEXTURE(texture) sfTexture_setRepeated(texture, sfTrue)
    #define CLEAR_WINDOW(window) sfRenderWindow_clear(window, sfBlack)
    #define DISPLAY_WINDOW(window) sfRenderWindow_display(window)
    #define DRAW_SPRITE(win, sp) sfRenderWindow_drawSprite(win, sp, NULL)
    #define IRECT(l, t, w, h) (sfIntRect){l, t, w, h}
    #define FRECT(l, t, w, h) (sfFloatRect){l, t, w, h}
    #define VECF(x, y) (sfVector2f){x, y}
    #define VECI(x, y) (sfVector2i){x, y}
#endif