/*
** EPITECH PROJECT, 2020
** lcalloc
** File description:
** lodeus_lib
*/

#include <lodeus/ctypes.h>
#include <lodeus/string.h>
#include <stdlib.h>

void *lcalloc(size_t nmemb, size_t size)
{
    void *new_alloc = malloc(nmemb *size);

    return (lmemset(new_alloc, 0, nmemb * size));
}
