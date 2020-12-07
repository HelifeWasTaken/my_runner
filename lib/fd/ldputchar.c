/*
** EPITECH PROJECT, 2020
** ldputchar
** File description:
** lodeus_lib
*/

#include <unistd.h>

size_t ldputchar(int fd, int c)
{
    return (write(fd, &c, 1));
}
