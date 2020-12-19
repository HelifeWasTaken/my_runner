/*
** EPITECH PROJECT, 2020
** my_stdio
** File description:
** my_stdio_for_the_epitech_curriculum
*/

#pragma once

#ifndef _MY_STDIO_H_
        #define _MY_STDIO_H_
        #include <stdarg.h>
        #include <stddef.h>
        #include <stdbool.h>
        size_t my_putchar(const char c);
        size_t fd_putchar(int const fd, const char c);
        size_t my_putstr(char const *str);
        size_t fd_putstr(int const fd, char const *str);

        size_t my_putnbr(long long nb);
        size_t fd_putnbr(int const fd, long long nb);
        size_t my_putnbr_unsigned(long long nb);
        size_t fd_putnbr_unsigned(int const fd, long long nb);
        size_t my_putnbr_base(long long nb, const int base,
                bool const uppercase);
        size_t fd_putnbr_base(int const fd, long long nb,
                int const base, bool const uppercase);

        size_t my_putnbr_base_unsigned(unsigned long long nb, unsigned int base,
                bool uppercase);
        size_t fd_putnbr_base_unsigned(int fd, unsigned long long nb,
                unsigned int base, bool uppercase);
        size_t my_putfloat(double nb, int precision);
        int my_printf(char const *str, ...);
        int my_dprintf(int fd, char const *str, ...);
        int my_vdprintf(int fd, char const *str, va_list *arg);
        #define BLACK  "\033[0;30m"
        #define RED    "\033[0;31m"
        #define GREEN  "\033[0;32m"
        #define YELLOW "\033[0;33m"
        #define BLUE   "\033[0;34m"
        #define PURPLE "\033[0;35m"
        #define CYAN   "\033[0;36m"
        #define WHITE  "\033[0;37m"
        #define DEFAULT "\033[0;00m"
        #define PRINTF_DEBUG(format, ...) \
        my_printf(GREEN"%s:%d " "-> "BLUE "[" format "]\n" DEFAULT, \
                __FILE__, __LINE__, ## __VA_ARGS__)
#endif
