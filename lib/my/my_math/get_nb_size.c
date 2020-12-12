/*
** EPITECH PROJECT, 2020
** get_nb_size_base.c
** File description:
** get_a_number_asize
*/

#include <my_stdio.h>
#include <stddef.h>

size_t get_nb_size(long long nb, int const base)
{
    int count = 1;

    if (nb < 0) {
        nb = -nb;
        count++;
    }
    while (nb >= base) {
        nb /= base;
        count++;
    }
    return (count);
}
