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

    enum {
        SMALL,
        MEDIUM,
        LARGE
    };

    typedef struct game_manager {
        sfRenderWindow *window;
        sfClock *clock;
        sfEvent event;
        u_int64_t score;
        u_int8_t state;
        char *map;
        bool infinty_enabled;
        sfVector2u screen_size;
        int8_t type_window;
    } game_manager_t;

    ////////////////////////// WINDOW INFO //////////////////////////////////

    #define WINDOW_NAME             "my_runner"
    #define WIN_W                   manager->screen_size.x
    #define WIN_H                   manager->screen_size.y
    #define WIN_MODE                \
        (sfVideoMode){manager.screen_size.x, manager.screen_size.y, 32}
    #define WIN_MODE_2              \
        (sfVideoMode){manager->screen_size.x, manager->screen_size.y, 32}


    /////////////////////////////// MISC ///////////////////////////////////

    void fake_wait_message(char *message);
    char *getoneline(char *pathfile);
    char *concat_string(char *s1, char *s2);
    char *handle_keyboard(char *buf);

    //////////////////////////////// USAGE ////////////////////////////////

    #define SHOW_HELP \
        my_putstr(PURPLE"MY_RUNNER\n\n" \
            BLUE"\tTo launch it use :"GREEN" ./my_runner [map] -> map mode" \
            BLUE" or "GREEN"./my_runner -i -> infinite mode\n" \
            BLUE"\tTo see this help use:"GREEN" ./my_runner -h\n" \
            PURPLE"\nDESCRIPTION:\n\n" \
            YELLOW"\tThis game is greatly inspired by the dinosaur game" \
            " from chrome\n\n\tThe are two modes :\n\t\t" \
            BLUE"Inifinite mode:"GREEN" Try to get as far" \
            " as possible and get the highest score!\n\t\t" \
            BLUE"Map mode: "GREEN"Try to end the map given in" \
            " argument without dying\n\t\t" \
            PURPLE"\nUSEFUL INFO:\n\n" \
            BLUE"\tIn the menu:"GREEN"\n\t\tYou can still modify" \
            " the map file\n\t\t" \
            "in map mode by typing directly the name of the file\n\t\t" \
            "a little text box" \
            " will appear under the quit button.\n\t\t" \
            "You can press F1 key to resize the window\n\t" \
            "and F2 key to modify your player !!!\n\t" \
            YELLOW"-> This option is not aviable in infinity mode\n\n\t" \
            BLUE"After finishing a game in inifnity mode:\n\t\t" \
            GREEN"You will see the"\
            " top 3 of the players.\n\t\tYou can enter your name by" \
            " typing with the keyboard\n\t\t" \
            "if you did not give a" \
            " username your score won't be registered!\n\t" \
            YELLOW"-> The scoreboard is only aviable in infinity mode\n" \
            PURPLE"\nCOMMANDS:\n\n" \
            BLUE"\tSpace bar: "GREEN"Jump "YELLOW"\n" \
            BLUE"\tEnter/Return: " \
            GREEN"Validate"YELLOW"(menu and end)\n\n"BLUE \
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
