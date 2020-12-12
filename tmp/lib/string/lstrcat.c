/*
** EPITECH PROJECT, 2020
** lstrcat
** File description:
** lodeus_lib
*/

#include <lodeus/string.h>

char *lstrcat(char *dest, char *src)
{
    lstrcpy(dest + lstrlen(dest), src);
    return (dest);
}
