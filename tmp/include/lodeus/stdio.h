/*
** EPITECH PROJECT, 2020
** lstdio
** File description:
** lodeus_lib
*/

#pragma once

#ifndef __LODEUS__STDIO__H__
#define __LODEUS__STDIO__H__
#include <lodeus/ctypes.h>
#include <stdarg.h>
    bool lprint_check_error_format(char const *format);

    size_t lprintf(char const *format, ...);

    size_t ldprintf(int fd, char const *format, ...);
    size_t lvdprintf(int fd, char const *format, va_list *ap);

    size_t lsprintf(char *str, char const *format, ...);
    size_t lvsprintf(char const *str, va_list *ap);

    size_t lasprintf(char *str, char const *format, ...);
    size_t lvasprintf(char *str, char const *format, va_list *ap);

    size_t lputchar(char const c);
    size_t lputs(char const *str);

    size_t lputnbr(long long nb);
    size_t lputnbr_u(unsigned long long nb);
    size_t lputnbr_base(long long nb, unsigned int base, bool uppercase);
    size_t lputfloat(double nb);
    #ifndef STDOUT_FILENO
        #define STDOUT_FILENO 1
        #define STDERR_FILENO 2
        #define STDIN_FILENO 0
    #endif
#endif

