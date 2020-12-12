/*
** EPITECH PROJECT, 2020
** lstrcmp
** File description:
** lodeus_lib
*/

#include <lodeus/ctypes.h>

static int is_ascci_high_or_low(char const c1, char const c2)
{
    return ((c1 > c2) ? 1 : -1);
}

int lstrcmp(char const *s1, char const *s2)
{
    size_t i = 0;

    while (s1[i] && s2[i]) {
        if (s1[i] != s2[i])
            return (is_ascci_high_or_low(s1[i], s2[i]));
        i++;
    }
    return ((s1[i] == s2[i]) ? 0 : is_ascci_high_or_low(s1[i], s2[i]));
}
