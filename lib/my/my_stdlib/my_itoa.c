/*
** EPITECH PROJECT, 2020
** my_itoa
** File description:
** iota
*/

#include <stddef.h>
#include <my_str.h>
#include <stdbool.h>
#include <my_stdio.h>

void my_itoa(long long value, char *to_fill, char const *base)
{
    size_t i = 0;
    size_t size_base = my_strlen(base);
    bool is_neg = false;

    if (value < 0) {
        value = -value;
        is_neg = true;
    }
    do {
        to_fill[i] = base[value % size_base];
        i++;
        value /= size_base;
    } while (value > 0);
    if (is_neg)
        to_fill[i++] = '-';
    to_fill[i] = '\0';
    my_revstr(to_fill);
}
