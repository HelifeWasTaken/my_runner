/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** Concatenation of two strings
*/

#include <stddef.h>

size_t my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    size_t i = 0;
    size_t len_of_src = my_strlen(dest);

    while (src[i]) {
        dest[i + len_of_src] = src[i];
        i++;
    }
    dest[i + len_of_src] = '\0';
    return (dest);
}
