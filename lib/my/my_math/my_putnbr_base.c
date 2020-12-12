/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** Printing numbers
*/

#include <stdbool.h>
#include <stddef.h>

size_t fd_putchar(int fd, char const c);

static size_t process_number(int const fd,
        long long nb, int const base_size, char const *base)
{
    return (
            (nb >= base_size) ?
            process_number(fd, nb / base_size, base_size, base) +
            fd_putchar(fd, base[nb % base_size]) :
            fd_putchar(fd, base[nb])
            );
}

size_t fd_putnbr_base(int const fd, long long nb, int const base_size,
        bool const uppercase)
{
    char const base_higher[36] = "0123456789ABCDEFGHJKLMNOPQRSTUVWXZ";
    char const base_lower[36] = "0123456789abcdefghijklmnopqrstuvwxyz";
    bool minus = false;

    if (nb < 0) {
        nb = -nb;
        fd_putchar(fd, '-');
        minus = true;
    }
    if (uppercase)
        return (process_number(fd, nb, base_size, base_higher) + minus);
    else
        return (process_number(fd, nb, base_size, base_lower) + minus);
}

size_t my_putnbr_base(long long nb, int const base_size, bool const uppercase)
{
    return (fd_putnbr_base(1, nb, base_size, uppercase));
}