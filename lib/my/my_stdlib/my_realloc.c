/*
** EPITECH PROJECT, 2020
** my_realloc
** File description:
** reallocate_a_string
*/

#include <stddef.h>
#include <stdlib.h>

void *my_memcpy(void *dest, const void *src, size_t n);

void *my_realloc(void *ptr, size_t size)
{
    void *new_alloc = malloc(size);

    if (new_alloc)
        my_memcpy(new_alloc, ptr, size);
    free (ptr);
    return (new_alloc);
}

int main(void)
{
    malloc(-1);
    return (0);
}
