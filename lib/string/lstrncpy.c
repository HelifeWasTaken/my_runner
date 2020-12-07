/*
** EPITECH PROJECT, 2020
** lstrncpy
** File description:
** lodeus_lib
*/

#include <lodeus/ctypes.h>

char *lstrncpy(char *dest, char const *src, size_t n)
{
    size_t i;

    for (i = 0; src[i] && i < n; i++)
        dest[i] = src[i];
    if (i < n)
        dest[i] = '\0';
    return (dest);
}
