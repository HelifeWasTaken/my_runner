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
        END,
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
        bool infinty_enabled;
    } game_manager_t;

    ////////////////////////// WINDOW INFO //////////////////////////////////

    #define WINDOW_NAME             "my_runner"
    #define WIN_W                   1300
    #define WIN_H                   768
    #define WIN_MODE                (sfVideoMode) {WIN_W, WIN_H, 32}

    /////////////////////////////// MISC ///////////////////////////////////

    void fake_wait_message(char *message);
    char *getoneline(char *pathfile);
    char *concat_string(char *s1, char *s2);
    char *handle_keyboard(char *buf);

    //////////////////////////////// USAGE ////////////////////////////////

    #define SHOW_HELP \
        my_printf(YELLOW"MY_RUNNER\n\n" \
            BLUE"\tTo launch it use :" GREEN" ./my_runner [map]\n" \
            BLUE"\tTo see this help use:" GREEN" ./my_runner -h\n" \
            PURPLE"\nDESCRIPTION:\n\n" \
            CYAN"\t\tTODO\n\n" \
            RED"Mattis DALLEAU\n"DEFAULT);

    #define SHOW_TOO_MUCH_ARGS \
        my_dprintf(2, RED"my_runner: " YELLOW"You have given too " \
            "much arguments or too less arguments\n" \
            CYAN"Try :"PURPLE" ./my_runner -h for the help\n"DEFAULT);

    #define SHOW_WRONG_ARG \
        my_dprintf(2, RED"my_runner :" \
            YELLOW"\n\tYou have given a wrong argument !\n" \
            CYAN"You can try :" GREEN"\n\t./my_runner -h to" \
            " show the help\n"DEFAULT);

    #define SHOW_ERROR_LOG_UNSUPORTED_CHAR \
        my_dprintf(2, RED"my_runner: "YELLOW"The map is not formatted well : " \
            "[%c|0x%x] is not supported\n"DEFAULT, buff[i], buff[i]);

    #define SHOW_ERROR_LOG_OPEN_FILE_FAIL(file) \
        my_dprintf(2, RED"my_runner: " \
            YELLOW"Could not open file : %s\n"DEFAULT, file)

    static inline int usage(int ac, char **av)
    {
        if (ac > 2 || ac == 1) {
            SHOW_TOO_MUCH_ARGS
            return (-1);
        }
        if (av[1][0] != '-')
            return (1);
        if (my_strcmp(av[1], "-i") == 0)
            return (2);
        if (my_strcmp(av[1], "-h") == 0) {
            SHOW_HELP
            return (0);
        }
        SHOW_WRONG_ARG
        return (-1);
    }

#endif
