/*
** EPITECH PROJECT, 2020
** lvdprintf_local_char
** File description:
** lodeus_lib
*/

#include <lodeus/fd.h>
#include <stdarg.h>
#include <lodeus/lvprintf/flag_modif.h>

size_t lvdprintf_local_char(int fd, va_list *ap, fl_modif_t modif)
{
    long long c = parse_type(ap, &modif);

    return (ldprint_loop(fd, ' ', modif.padding_left) + ldputchar(fd, c) +
        ldprint_loop(fd, ' ', modif.padding_right));
}

