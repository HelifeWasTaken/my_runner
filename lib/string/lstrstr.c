/*
** EPITECH PROJECT, 2020
** lstrstr.c
** File description:
** Move pointer to the occurence found
*/

#include <lodeus/ctypes.h>
#include <lodeus/string.h>

char *lstrstr(char *haystack, char const *needle)
{
    size_t size_needle = lstrlen(needle);
    size_t i = 0;

    if (!(*needle))
        return (haystack);
    while (*haystack + i) {
        if (lstrncmp(haystack + i, needle, size_needle) == 0)
            return (&haystack[i]);
        i++;
        size_needle--;
    }
    return (NULL);
}
