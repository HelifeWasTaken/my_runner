/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** Copy str to dest for n size
*/

#include <stddef.h>

char *my_strncpy(char *dest, char const *src, size_t const n)
{
    size_t i = 0;

    while (src[i] && i < n) {
        dest[i] = src[i];
        i++;
    }
    while (i < n) {
        dest[i] = '\0';
        i++;
    }
    return (dest);
}
