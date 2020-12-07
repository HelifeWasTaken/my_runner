/*
** EPITECH PROJECT, 2020
** lmemset
** File description:
** lodeus_lib
*/

#include <lodeus/ctypes.h>

void *lmemset(void *s, int c, size_t n)
{
    unsigned char *s_ptr = (unsigned char *)s;

    while (--n)
        *s_ptr++ = c;
    return (s);
}
