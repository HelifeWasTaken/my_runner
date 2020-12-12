/*
** EPITECH PROJECT, 2020
** lstrlen
** File description:
** lodeus_lib
*/

#include <lodeus/ctypes.h>

size_t lstrlen(char const *str)
{
    size_t i = 0;

    if (str) {
        while (str[i])
            i++;
    }
    return (i);
}
