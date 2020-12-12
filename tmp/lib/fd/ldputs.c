/*
** EPITECH PROJECT, 2020
** ldputs
** File description:
** lodeus_lib
*/

#include <lodeus/string.h>
#include <unistd.h>

size_t ldputs(int fd, char const *str)
{
    size_t size_str = lstrlen(str);

    return (write(fd, str, size_str) + write(fd, "\n", 1));
}
