/*
** EPITECH PROJECT, 2020
** lrealloc
** File description:
** lodeus_lib
*/

#include <lodeus/ctypes.h>
#include <stdlib.h>
#include <lodeus/string.h>

void *lrealloc(void *old_ptr, size_t old_size, size_t new_size)
{
    void *new_ptr;

    if (!old_size)
        return (malloc(new_size));
    if (new_size < old_size)
        return (old_ptr);
    new_ptr = malloc(new_size);
    if (new_ptr)
        lmemcpy(new_ptr, old_ptr, old_size + 1);
    free(old_ptr);
    return (new_ptr);
}
