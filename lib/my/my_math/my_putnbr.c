/*
** EPITECH PROJECT, 2020
** my_putnbr
** File description:
** putnbr
*/

#include <stddef.h>

size_t fd_putchar(const int fd, char const c);

static size_t fd_putnbr_rec(const int fd, long long nb)
{
    return ((nb >= 10) ? fd_putnbr_rec(fd, nb / 10) +
            fd_putchar(fd, nb % 10 + '0') :
            fd_putchar(fd, nb + '0'));
}

size_t fd_putnbr(const int fd, long long nb)
{
    return ((nb < 0) ? fd_putchar(fd, '-') + fd_putnbr_rec(fd, -nb) :
            fd_putnbr_rec(fd, nb));
}

size_t my_putnbr(long long nb)
{
    return (fd_putnbr(1, nb));
}
