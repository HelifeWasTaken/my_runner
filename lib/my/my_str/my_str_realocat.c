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
    size_t len_of_src = my_strlen(src);
    size_t len_of_dest = my_strlen(dest);
    char *new_alloc = my_calloc(sizeof(char), (len_of_dest + len_of_src) + 50);

    my_strcat(new_alloc, dest);
    my_strcat(new_alloc, src);
    free(src);
    free(dest);
    return (new_alloc);
}
