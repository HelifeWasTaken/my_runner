/*
** EPITECH PROJECT, 2020
** lmemcmp
** File description:
** lodeus_lib
*/

#include <lodeus/ctypes.h>

static int is_lower_or_higher(char c1, char c2)
{
    return ((c1 < c2) ? 1 : -1);
}

int lmemcmp(const void *s1, const void *s2, size_t n)
{
    char *s1_ptr = (char *)s1;
    char *s2_ptr = (char *)s2;

    while (--n) {
        if (*s1_ptr != *s2_ptr)
            return (is_lower_or_higher(*s1_ptr, *s2_ptr));
        s1_ptr++;
        s2_ptr++;
    }
    return ((*s1_ptr == *s2_ptr) ? 0 : is_lower_or_higher(*s1_ptr, *s2_ptr));
}
