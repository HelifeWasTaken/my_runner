/*
** EPITECH PROJECT, 2020
** my_memcpy
** File description:
** my_memcpy
*/

#include <stddef.h>

void *my_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *dest_temp = (unsigned char *)dest;
    const unsigned char *src_temp = (unsigned char *)src;

    while (n--)
        *dest_temp++ = *src_temp++;
    return (dest);
}
