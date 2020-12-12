/*
** EPITECH PROJECT, 2020
** print_my_char_in_loop
** File description:
** print_a_char_with_a_loop
*/

#include <stddef.h>

size_t fd_putchar(int const fd, char const c);

size_t fd_print_char_in_loop(int const fd, int const count, char const c)
{
    for (int i = 0; i < count; i++)
        fd_putchar(fd, c);
    return (count);
}

size_t print_char_in_loop(int const count, char const c)
{
    return (fd_print_char_in_loop(1, count, c));
}
