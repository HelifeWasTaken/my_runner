/*
** EPITECH PROJECT, 2020
** lvdprintf_local_int
** File description:
** lodeus_lib
*/

#include <lodeus/fd.h>
#include <stdarg.h>
#include <lodeus/lvprintf/flag_modif.h>

size_t lvdprintf_local_int(int fd, va_list *ap,
        struct flag_modifiers modif)
{
    long long nb = parse_type(ap, &modif);
    long long count = 0;

    if (modif.precision)
        count += ldprint_loop(fd, '0', modif.padding_left);
    if (modif.zero)
        count += ldprint_loop(fd, '0', modif.padding_left);
    else {
        count += ldprint_loop(fd, ' ', modif.padding_left);
        count += ldprint_loop(fd, ' ', modif.padding_right);
    }
    count += ldputnbr(fd, nb);
    return (count);
}
