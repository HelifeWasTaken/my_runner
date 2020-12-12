/*
** EPITECH PROJECT, 2020
** my_vn_putnbr
** File description:
** redirect_for_putnbr
*/

#include <stdarg.h>
#include <my_printf.h>
#include <my_math.h>

int
my_vn_putbin(va_list *arg, flag_modifiers_t modification_flag)
{
    unsigned long long nb = va_arg(*arg, unsigned long long);

    return (fd_putnbr_base_unsigned(modification_flag.fd, nb, 2, 0));
}
