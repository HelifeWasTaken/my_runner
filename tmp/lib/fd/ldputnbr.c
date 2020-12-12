/*
** EPITECH PROJECT, 2020
** ldputnbr
** File description:
** lodeus_lib
*/

#include <lodeus/fd.h>

static size_t process_putnbr(int fd, long long nb)
{
    return ((nb >= 10) ?
        process_putnbr(fd, nb / 10) + ldputchar(fd, nb % 10 + '0') :
        ldputchar(fd, nb + '0'));
}

size_t ldputnbr(int fd, long long nb)
{
    return ((nb < 0) ?
        ldputchar(fd, '-') + process_putnbr(fd, -nb) :
        process_putnbr(fd, nb));
}

size_t ldputnbr_u(int fd, long long nb)
{
    return ((nb >= 10) ?
        ldputnbr_u(fd, nb / 10) + ldputchar(fd, nb % 10 + '0') :
        ldputchar(fd, nb + '0'));
}
