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


static void prepare_print_int_precision(flag_modifiers_t *modification_flag)
{
    if (modification_flag->default_precision ||
            modification_flag->precision < 0)
        modification_flag->precision = 1;
    fd_print_char_in_loop(modification_flag->fd,
            modification_flag->precision, '0');
    modification_flag->already_printed += modification_flag->precision;
}

static void prepare_print_int(flag_modifiers_t *modification_flag,
        int to_be_printed)
{
    modification_flag->space_padding -= to_be_printed;
    modification_flag->precision -= to_be_printed;
    if (modification_flag->found_precision)
        prepare_print_int_precision(modification_flag);
    if (modification_flag->space_padding > 0) {
        if (modification_flag->zero)
            fd_print_char_in_loop(modification_flag->fd,
                    modification_flag->space_padding, '0');
        else
            fd_print_char_in_loop(modification_flag->fd,
                    modification_flag->space_padding, ' ');
        modification_flag->already_printed += modification_flag->space_padding;
        modification_flag->space_padding = 0;
    }
}

static long long parse_my_int(va_list *arg, flag_modifiers_t modification_flag)
{
    if ((my_strncmp(modification_flag.last_flag, "d", 1) == 0) ||
            (my_strncmp(modification_flag.last_flag, "i", 1) == 0))
        return ((int)va_arg(*arg, int));
    if ((my_strncmp(modification_flag.last_flag, "ld", 2) == 0) ||
            (my_strncmp(modification_flag.last_flag, "li", 2) == 0))
        return ((long)va_arg(*arg, long));
    if ((my_strncmp(modification_flag.last_flag, "lld", 3) == 0) ||
            (my_strncmp(modification_flag.last_flag, "lli", 3) == 0) ||
            (my_strncmp(modification_flag.last_flag, "qd", 2) == 0) ||
            (my_strncmp(modification_flag.last_flag, "qi", 2) == 0))
        return ((long long)va_arg(*arg, long long));
    if ((my_strncmp(modification_flag.last_flag, "hhd", 3) == 0) ||
            (my_strncmp(modification_flag.last_flag, "hhi", 3) == 0))
        return ((char)va_arg(*arg, int));
    return ((short int)va_arg(*arg, int));
}

int my_vn_putnbr(va_list *arg, flag_modifiers_t modification_flag)
{
    long long nb = parse_my_int(arg, modification_flag);

    prepare_print_int(&modification_flag, get_nb_size(nb, 10));
    return (fd_putnbr(modification_flag.fd, nb) +
            modification_flag.already_printed);
}
