/*
** EPITECH PROJECT, 2020
** my_put_pointer.c
** File description:
** Printing numbers
*/

#include <stdbool.h>
#include <stddef.h>

size_t fd_putstr(int fd, char const *str);

size_t fd_putchar(int fd, char const c);

static size_t process_number(int fd, long nb, int base_size, char const *base)
{
    return ((nb >= base_size) ?
            process_number(fd, nb / base_size, base_size, base) +
            fd_putchar(fd, base[nb % base_size]) :
            fd_putchar(fd, base[nb]));
}

size_t fd_putpointer(int fd, long nb)
{
    return (fd_putstr(fd, "0x" +
                process_number(fd, nb, 16, "0123456789abcdef")));
}

size_t my_putpointer(long nb)
{
    return (fd_putpointer(1, nb));
}
