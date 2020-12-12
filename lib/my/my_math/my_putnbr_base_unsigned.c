/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** Printing numbers
*/

#include <stdbool.h>
#include <stddef.h>

size_t fd_putchar(int fd, char const c);

static size_t process_number(int fd,
        long long unsigned nb, unsigned int base_size, char const *base)
{
    return (
            (nb >= base_size) ?
            process_number(fd, nb / base_size, base_size, base) +
            fd_putchar(fd, base[nb % base_size]) :
            fd_putchar(fd, base[nb])
            );
}

size_t fd_putnbr_base_unsigned(int fd, long long unsigned nb,
unsigned int base_size, bool uppercase)
{
    char const base_higher[36] = "0123456789ABCDEFGHJKLMNOPQRSTUVWXZ";
    char const base_lower[36] = "0123456789abcdefghijklmnopqrstuvwxyz";

    if (uppercase)
        return (process_number(fd, nb, base_size, base_higher));
    else
        return (process_number(fd, nb, base_size, base_lower));
}

size_t my_putnbr_base_unsigned(long long unsigned nb, unsigned int base_size,
        bool uppercase)
{
    return (fd_putnbr_base_unsigned(1, nb, base_size, uppercase));
}
