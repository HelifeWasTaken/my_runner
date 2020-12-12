/*
** EPITECH PROJECT, 2020
** my_memset.c
** File description:
** implement_memset
*/

#include <stddef.h>

void *my_memset(void *data, int filler, size_t size)
{
    unsigned char *pointer_filler = (unsigned char *)data;

    while (size) {
        *pointer_filler = filler;
        pointer_filler++;
        size--;
    }
    return (data);
}