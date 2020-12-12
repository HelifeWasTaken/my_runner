/*
** EPITECH PROJECT, 2020
** print_char_in_hex
** File description:
** print_in_hex
*/

#include <stdbool.h>
#include <stddef.h>

size_t fd_putchar(int const fd, char const c);

size_t fd_putnbr_base(int fd, long long nb, int const base,
        bool const uppercase);

size_t fd_putstr(int const fd, char const *str);

size_t fd_print_char_in_oct(int fd, unsigned char c)
{
    size_t count = 0;

    count += fd_putchar(fd, '\\');
    if (c < 0x7)
        count += fd_putstr(fd, "00");
    else if (c > 0x7 && c <= 0x3F)
        count += fd_putstr(fd, "0");
    return (fd_putnbr_base(fd, c, 8, 1) + count);
}

size_t print_char_in_oct(unsigned char c)
{
    return (fd_print_char_in_oct(1, c));
}
