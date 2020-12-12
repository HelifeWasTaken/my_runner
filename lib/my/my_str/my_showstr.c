/*
** EPITECH PROJECT, 2020
** my_showstr.c
** File description:
** Print every non printable character with their hex value
*/

#include <stddef.h>

size_t fd_putchar(const int fd, char c);

size_t fd_putstr(const int fd, char const *str);

size_t fd_print_char_in_hex(const int fd, unsigned char c);

size_t fd_showstr(const int fd, char const *str)
{
    size_t i;

    for (i = 0; str[i]; i++) {
        if (!(str[i] >= 32) && str[i] <= 126)
            fd_print_char_in_hex(fd, str[i]);
        else
            fd_putchar(fd, str[i]);
    }
    return (i);
}

size_t my_showstr(char const *str)
{
    return (fd_showstr(1, str));
}
