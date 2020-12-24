/*
** EPITECH PROJECT, 2020
** my_itoa
** File description:
** iota
*/

#include <stddef.h>
#include <my_str.h>
#include <stdbool.h>
#include <stdlib.h>
#include <my_stdlib.h>

char *my_itoa(long long value, char const *base)
{
    size_t i = 0;
    size_t size_base = my_strlen(base);
    char *to_fill = malloc(sizeof(char) * (get_nb_size(value, size_base) + 1));
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
    return (my_revstr(to_fill));
}
