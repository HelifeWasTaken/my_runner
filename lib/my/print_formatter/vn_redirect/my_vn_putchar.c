/*
** EPITECH PROJECT, 2020
** my_vn_putchar
** File description:
** my_putchar_redirect
*/

#include <my_printf.h>
#include <stddef.h>

size_t fd_putchar(int fd, char const c);

int my_vn_putchar(va_list *arg, flag_modifiers_t flag_modificater)
{
    unsigned char c = va_arg(*arg, int);

    return (fd_putchar(flag_modificater.fd, c));
}