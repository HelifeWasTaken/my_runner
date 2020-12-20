/*
** EPITECH PROJECT, 2020
** my_runner.h
** File description:
** runner
*/

#pragma once

#ifndef __MY_RUNNER__H__
    #define __MY_RUNNER__H__
    #include <my_csfml.h>

    enum {
        GAME,
        MENU
    };

    typedef struct game_manager {
        sfRenderWindow *window;
        sfClock *clock;
        sfEvent event;
        u_int64_t score;
    } game_manager_t;

    #define WINDOW_NAME             "my_runner"
    #define WIN_W                   1536
    #define WIN_H                   768
    #define WIN_MODE                (sfVideoMode) {WIN_W, WIN_H, 32}

    void fake_wait_message(char *message);
    char *getoneline(char *pathfile);
#endif
