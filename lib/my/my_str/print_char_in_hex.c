/*
** EPITECH PROJECT, 2020
** print_char_in_hex
** File description:
** print_in_hex
*/

#include <stdbool.h>
#include <stddef.h>

size_t fd_putchar(int const fd, char const c);

size_t fd_putnbr_base(int const fd, long long const nb, int const base,
const bool uppercase);

size_t fd_print_char_in_hex(int const fd, unsigned char const c)
{
    size_t count = 0;

    count += fd_putchar(fd, '\\');
    if (c <= 0xF)
        count += fd_putchar(fd, '0');
    return (fd_putnbr_base(fd, c, 16, 0) + count);
}

size_t print_char_in_hex(unsigned char const c)
{
    return (fd_print_char_in_hex(1, c));
}
