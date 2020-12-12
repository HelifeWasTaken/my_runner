/*
** EPITECH PROJECT, 2020
** my_bzero
** File description:
** recreating_bzero
*/

#include <stdlib.h>
#include <stddef.h>

void *my_memset(void *data, int filler, size_t size);

void my_bzero(void *data, size_t size)
{
    my_memset(data, '\0', size);
}
