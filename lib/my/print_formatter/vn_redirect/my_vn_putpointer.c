/*
** EPITECH PROJECT, 2020
** my_vn_putnbr
** File description:
** redirect_for_putnbr
*/

#include <stdarg.h>
#include <my_printf.h>
#include <my_math.h>

size_t fd_putstr(int fd, char const *str);

int
my_vn_putpointer(va_list *arg, flag_modifiers_t modification_flag)
{
    unsigned long long nb = va_arg(*arg, unsigned long long);

    return (fd_putstr(modification_flag.fd, "0x") +
                fd_putnbr_base_unsigned(modification_flag.fd, nb, 16, 0));
}
