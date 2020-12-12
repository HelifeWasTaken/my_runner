/*
** EPITECH PROJECT, 2020
** lmemcpy
** File description:
** lodeus_lib
*/

#include <lodeus/ctypes.h>

void *lmemcpy(void *dest, void const *src, size_t n)
{
    char *dest_ptr = (char *)dest;
    char const *src_ptr = (char const *)src;

    while (--n)
        *dest_ptr++ = *src_ptr++;
    return (dest);
}
