/*
** EPITECH PROJECT, 2020
** my_math_libmy
** File description:
** libmy_for_the_epitech_curriculum
*/

#pragma once

#ifndef _MY_MATH_H_
#define _MY_MATH_H_
        #include <stdbool.h>
        #include <stddef.h>
        size_t get_nb_size(long long nb, int const base);
        size_t get_nb_size_unsigned(unsigned long long nb,
                unsigned int const base);
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
        size_t get_nb_size(long long nb, int base);
        size_t get_nb_size_unsigned(unsigned long long nb, unsigned int base);
        long long my_pow(long long nb, int power);
#endif
