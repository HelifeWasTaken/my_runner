/*
** EPITECH PROJECT, 2020
** lvdprintf_local_uint
** File description:
** lodeus_lib
*/

#include <lodeus/lvprintf/flag_modif.h>
#include <lodeus/fd.h>

size_t lvdprintf_local_uint(int fd, va_list *ap, fl_modif_t modif)
{
    unsigned long long nb = parse_typeu(ap, &modif);

    if (modif.zero) {
        return (ldprint_loop(fd, '0', modif.padding_left) +
            ldprint_loop(fd, '0', modif.precision) +
            ldputnbr_u(fd, nb));
    }
    return (ldprint_loop(fd, ' ', modif.padding_left) +
        ldprint_loop(fd, '0', modif.precision) +
        ldputnbr_u(fd, nb) +
        ldprint_loop(fd, ' ', modif.padding_right));
}
