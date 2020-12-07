/*
** EPITECH PROJECT, 2020
** lstrcpy
** File description:
** lodeus_lib
*/

#include <lodeus/ctypes.h>

char *lstrcpy(char *dest, char const *src)
{
    size_t i;

    for (i = 0; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
