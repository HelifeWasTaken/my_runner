/*
** EPITECH PROJECT, 2020
** lstrncat
** File description:
** lodeus_lib
*/

#include <lodeus/string.h>
#include <lodeus/ctypes.h>

char *lstrncat(char *dest, char const *src, size_t n)
{
    lstrncpy(dest + lstrlen(dest), src, n);
    return (dest);
}
