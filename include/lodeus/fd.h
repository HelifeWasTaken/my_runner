/*
** EPITECH PROJECT, 2020
** ldout
** File description:
** lodeus_lib
*/

#pragma once

#ifndef __LODEUS__LDOUT__H__
#define __LODEUS__LDOUT__H__
    #include <lodeus/ctypes.h>
    #include <stdarg.h>
    size_t ldshow_ptr(int fd, long long ptr_value);
    size_t ldprintf(int fd, char const *format, ...);
    size_t lvdprintf(int fd, char const *format, va_list *ap);
    size_t ldprint_loop(int fd, int c, size_t count);
    size_t ldputchar(int fd, int c);
    size_t ldputs(int fd, char const *str);
    size_t ldputnbr(int fd, long long nb);
    size_t ldputnbr_u(int fd, long long nb);
    size_t ldputfloat(int fd, double nb, unsigned char precision);
    size_t parser_lvdprintf(int fd, char const **format, va_list *ap);
    size_t ldputnbr_base(int fd, unsigned long long nb,
            unsigned int base, bool uppercase);
    #ifndef STDOUT_FILENO
        #define STDOUT_FILENO 1
        #define STDERR_FILENO 2
        #define STDIN_FILENO 0
    #endif
#endif
