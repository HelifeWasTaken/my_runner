/*
** EPITECH PROJECT, 2020
** get_nb_size_base.c
** File description:
** get_a_number_asize
*/

#include <my_stdio.h>
#include <stddef.h>

size_t get_nb_size_unsigned(unsigned long long nb, unsigned int const base)
{
    int count = 1;

    while (nb > base) {
        nb /= base;
        count++;
    }
    return (count);
}
