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


static void prepare_print_unsigned_int_precision(flag_modifiers_t
        *modification_flag)
{
    if (modification_flag->default_precision ||
            modification_flag->precision < 0)
        modification_flag->precision = 1;
    fd_print_char_in_loop(modification_flag->fd, modification_flag->precision,
            '0');
    modification_flag->already_printed += modification_flag->precision;
}

static void prepare_print_unsigned_int(flag_modifiers_t *modification_flag,
        int to_be_printed)
{
    modification_flag->space_padding -= to_be_printed;
    modification_flag->precision -= to_be_printed;
    if (modification_flag->found_precision)
        prepare_print_unsigned_int_precision(modification_flag);
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

static long long parse_my_unsigned_int(va_list *arg,
        flag_modifiers_t modification_flag)
{
    if (my_strncmp(modification_flag.last_flag, "u", 1) == 0)
        return ((unsigned int)va_arg(*arg, unsigned int));
    if (my_strncmp(modification_flag.last_flag, "lu", 2) == 0)
        return ((unsigned long)va_arg(*arg, unsigned long));
    if ((my_strncmp(modification_flag.last_flag, "llu", 3) == 0) ||
            (my_strncmp(modification_flag.last_flag, "qu", 2) == 0))
        return ((unsigned long long)va_arg(*arg, unsigned long long));
    if ((my_strncmp(modification_flag.last_flag, "hhu", 3) == 0))
        return ((char)va_arg(*arg, unsigned int));
    return ((short int)va_arg(*arg, unsigned int));
}

int my_vn_putunsigned(va_list *arg, flag_modifiers_t modification_flag)
{
    unsigned long long nb = parse_my_unsigned_int(arg, modification_flag);

    prepare_print_unsigned_int(&modification_flag,
            get_nb_size_unsigned(nb, 10));
    return (fd_putnbr_unsigned(modification_flag.fd, nb) +
            modification_flag.already_printed);
}
