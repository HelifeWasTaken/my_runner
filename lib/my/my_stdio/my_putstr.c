/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** Rewrite puts function
*/

#include <unistd.h>
#include <stddef.h>

size_t my_strlen(char const *str);

size_t fd_putstr(const int fd, char const *str)
{
    return (write(fd, str, my_strlen(str)));
}

size_t my_putstr(char const *str)
{
    return (fd_putstr(1, str));
}