/*
** EPITECH PROJECT, 2020
** lstr_realocat
** File description:
** lodeus_lib
*/

#include <lodeus/ctypes.h>
#include <lodeus/string.h>
#include <lodeus/stdlib.h>
#include <stdlib.h>

char *lstr_realocat(char *s1, char *s2)
{
    size_t size_s1 = lstrlen(s1);
    size_t size_s2 = lstrlen(s2);
    char *new_str = lrealloc(s1, sizeof(char) * (size_s1),
            sizeof(char) * (size_s1 + size_s2 + 1));

    lstrcat(new_str, s2);
    free(s2);
    return (new_str);
}
