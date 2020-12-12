/*
** EPITECH PROJECT, 2020
** lstrndup
** File description:
** lodeus_lib
*/

#include <lodeus/ctypes.h>
#include <stdlib.h>

char *lstrndup(char const *str, size_t n)
{
    char *new_str = malloc(sizeof(char) * (n + 1));
    size_t i;

    if (new_str) {
        for (i = 0; str[i] && i < n; i++)
            new_str[i] = str[i];
        for (; i < n; i++)
            new_str[i] = '\0';
    }
    new_str[n] = '\0';
    return (new_str);
}
