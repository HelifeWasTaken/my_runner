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
        MENU,
        GAME,
        QUIT
    };

    enum {
        GAME_CHOICE,
        QUIT_CHOICE
    };

    typedef struct game_manager {
        sfRenderWindow *window;
        sfClock *clock;
        sfEvent event;
        u_int64_t score;
        u_int8_t state;
        char *map;
    } game_manager_t;

    #define WINDOW_NAME             "my_runner"
    #define WIN_W                   1300 // 800
    #define WIN_H                   768
    #define WIN_MODE                (sfVideoMode) {WIN_W, WIN_H, 32}

    #define SHOW_HELP \
        my_printf(YELLOW"MY_RUNNER\n\n" \
                BLUE"\tTo launch it use :" GREEN" ./my_runner [map]\n" \
                BLUE"\tTo see this help use:" GREEN" ./my_runner -h\n" \
                PURPLE"\nDESCRIPTION:\n\n" \
                CYAN"\t\tTODO\n\n" \
                RED"Mattis DALLEAU\n"DEFAULT);


    void fake_wait_message(char *message);
    char *getoneline(char *pathfile);
#endif
