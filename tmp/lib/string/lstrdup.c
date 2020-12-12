/*
** EPITECH PROJECT, 2020
** lstrdup
** File description:
** lodeus_lib
*/

#include <lodeus/ctypes.h>
#include <lodeus/string.h>
#include <stdlib.h>

char *lstrdup(char const *src)
{
    size_t len = lstrlen(src) + 1;
    char *new_str = malloc(sizeof(char) * len);

    if (!new_str)
        return (NULL);
    lmemcpy(new_str, src, len);
    new_str[len - 1] = '\0';
    return (new_str);
}
