/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** Printing numbers
*/

#include <stddef.h>

size_t fd_putchar(const int fd, const char c);

size_t fd_putnbr_unsigned(const int fd, unsigned long long nb)
{
    return ((nb >= 10) ?
        fd_putnbr_unsigned(fd, nb / 10) + fd_putchar(fd, (nb % 10) + '0') :
        fd_putchar(fd, nb + '0'));
}

size_t my_putnbr_unsigned(unsigned long long nb)
{
    return (fd_putnbr_unsigned(1, nb));
}
