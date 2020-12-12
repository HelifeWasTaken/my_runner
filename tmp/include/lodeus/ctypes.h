/*
** EPITECH PROJECT, 2020
** dctype
** File description:
** lodeus_lib
*/

#pragma once

#ifndef __LODEUS_CTYPE__H__
    #include <sys/types.h>
    #include <stddef.h>
    #include <stdint.h>
    #include <stdbool.h>
    #include <limits.h>
    #ifndef STDOUT_FILENO
        #define STDOUT_FILENO 1
        #define STDERR_FILENO 2
        #define STDIN_FILENO 0
    #endif
    bool lisalpha(int c);
    bool lisnum(int c);
    bool lisalphanum(int c);
    bool lisprintable(int c);
    bool lislower(int c);
    bool lisupper(int c);
    bool lisspace(int c);
    bool lispunct(int c);
    int ltolower(int c);
    int ltoupper(int c);
#endif

