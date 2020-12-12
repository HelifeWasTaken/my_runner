/*
** EPITECH PROJECT, 2020
** lstrchr.c
** File description:
** Move pointer to the occurence found
*/

#include <lodeus/ctypes.h>

char *lstrchr(char *str, int c)
{
    if (!c)
        return (str);
    for (size_t i = 0; *str + i; i++) {
        if (str[i] == c)
            return (&str[i]);
    }
    return (NULL);
}
