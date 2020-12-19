/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** Concatenation of two strings
*/

#include <stddef.h>
#include <my_str.h>
#include <my_stdlib.h>
#include <stdlib.h>
#include <my_stdio.h>

char *my_str_realocat(char *dest, char *src)
{
    char *new_alloc = NULL;

    if (!dest)
        return (src);
    new_alloc = my_calloc(sizeof(char), (my_strlen(dest) + my_strlen(src) + 1));
    my_memcpy(new_alloc, dest, my_strlen(dest));
    my_strcat(new_alloc, src);
    free(src);
    free(dest);
    return (new_alloc);
}
