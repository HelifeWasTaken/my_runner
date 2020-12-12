/*
** EPITECH PROJECT, 2020
** ldprint_loop
** File description:
** lodeus_lib
*/

#include <lodeus/fd.h>

size_t ldprint_loop(int fd, int c, size_t count)
{
    for (size_t i = 0; i < count; i++)
        ldputchar(fd, c);
    return (count);
}
