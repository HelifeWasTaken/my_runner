/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** Detect if a string is the same
*/

#include <stddef.h>

int my_strncmp(char const *s1, char const *s2, size_t const n)
{
    for (size_t i = 0; (s1[i] || s2[i]) && i < n; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (0);
}
