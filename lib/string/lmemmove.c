/*
** EPITECH PROJECT, 2020
** lmemmove
** File description:
** lodeus_lib
*/

#include <lodeus/string.h>
#include <lodeus/ctypes.h>

void *llmemmove(void *dest, void *src, size_t n)
{
    char *dest_ptr = (char *)dest;
    char *src_ptr = (char *)src;
    char tmp_array[n];

    for (size_t i = 0; i < n; i++)
        tmp_array[i] = src_ptr[i];
    for (size_t i = 0; i < n; i++)
        dest_ptr[i] = tmp_array[i];
    return (dest);
}

