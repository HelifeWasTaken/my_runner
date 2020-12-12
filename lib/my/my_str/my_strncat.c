/*
** EPITECH PROJECT, 2020
** my_strncat.c
** File description:
** Concatenate n bytes of two strings
*/

#include <stddef.h>

size_t my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, size_t const nb)
{
    size_t i = 0;
    size_t len_of_src = my_strlen(dest);

    if (!len_of_src)
        return (dest);
    while (src[i] && i < nb) {
        dest[i + len_of_src] = src[i];
        i++;
    }
    dest[i + len_of_src] = '\0';
    return (dest);
}
