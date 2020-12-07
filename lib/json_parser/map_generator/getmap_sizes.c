/*
** EPITECH PROJECT, 2020
** getmap_sizes.c
** File description:
** lodeus_lib
*/

#include <stddef.h>

size_t getmap_width(char *buffer)
{
    size_t count = 0;

    for (size_t i = 0; buffer[i] != '\n'; i++) {
        if (buffer[i] == ',')
            count++;
    }
    return (count);
}

size_t getmap_height(char *buffer)
{
    size_t count = 0;

    for (size_t i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            count++;
    }
    return (count);
}
