/*
** EPITECH PROJECT, 2020
** my_putchar_program
** File description:
** put a char
*/

#include <stddef.h>
#include <unistd.h>

size_t fd_putchar(const int fd, char const c)
{
    return (write(fd, &c, 1));
}

size_t my_putchar(const char c)
{
    return (fd_putchar(1, c));
}
