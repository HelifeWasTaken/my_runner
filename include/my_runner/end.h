/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** end
*/

#pragma once

#ifndef __MY__RUNNER__END__H__
    #define __MY__RUNNER__END__H__
    #include <my_csfml.h>
    #include <my_runner/score.h>

    typedef struct end {
        sfMusic *music;
        sfSprite *sprite_bg;
        sfTexture *texture_bg;
        char *top_str;
        sfText *score_board;
        char *username;
        sfText *username_text;
    } end_t;

    #define END_MUSIC_ASSET         "asset/end.ogg"
    #define END_BG_ASSET            "asset/end.png"
#endif