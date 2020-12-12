/*
** EPITECH PROJECT, 2020
** my_vn_putnbr
** File description:
** redirect_for_putnbr
*/

#include <stdarg.h>
#include <my_printf.h>
#include <stddef.h>
#include <my_str.h>
#include <my_math.h>


static unsigned long long parse_my_upper_hex(va_list *arg,
        flag_modifiers_t modification_flag)
{
    if (my_strncmp(modification_flag.last_flag, "X", 1) == 0)
        return ((unsigned int)va_arg(*arg, unsigned int));
    if (my_strncmp(modification_flag.last_flag, "lX", 2) == 0)
        return ((unsigned long)va_arg(*arg, unsigned long));
    if ((my_strncmp(modification_flag.last_flag, "llX", 3) == 0) ||
        (my_strncmp(modification_flag.last_flag, "qX", 2) == 0))
        return ((unsigned long)va_arg(*arg, unsigned long long));
    if (my_strncmp(modification_flag.last_flag, "hhX", 3) == 0)
        return ((char)va_arg(*arg, unsigned int));
    return ((short int)va_arg(*arg, unsigned int));
}

int my_vn_puthex_upper(va_list *arg, flag_modifiers_t modification_flag)
{
    unsigned long long nb = parse_my_upper_hex(arg, modification_flag);

    return (fd_putnbr_base_unsigned(modification_flag.fd, nb, 16, 1));
}

static unsigned long long parse_my_lower_hex(va_list *arg,
        flag_modifiers_t modification_flag)
{
    if (my_strncmp(modification_flag.last_flag, "x", 1) == 0)
        return ((unsigned int)va_arg(*arg, unsigned int));
    if (my_strncmp(modification_flag.last_flag, "lx", 2) == 0)
        return ((unsigned long)va_arg(*arg, unsigned long));
    if ((my_strncmp(modification_flag.last_flag, "llx", 3) == 0) ||
        (my_strncmp(modification_flag.last_flag, "qx", 2) == 0))
        return ((unsigned long)va_arg(*arg, unsigned long long));
    if (my_strncmp(modification_flag.last_flag, "hhx", 3) == 0)
        return ((char)va_arg(*arg, unsigned int));
    return ((short int)va_arg(*arg, unsigned int));
}

int my_vn_puthex_lower(va_list *arg, flag_modifiers_t modification_flag)
{
    unsigned long long nb = parse_my_lower_hex(arg, modification_flag);

    return (fd_putnbr_base_unsigned(modification_flag.fd, nb, 16, 0));
}
