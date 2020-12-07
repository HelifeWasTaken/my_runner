/*
** EPITECH PROJECT, 2020
** lvdprintf_local_oct
** File description:
** lodeus_lib
*/

#include <lodeus/fd.h>
#include <lodeus/lvprintf/flag_modif.h>

size_t lvdprintf_local_oct(int fd, va_list *ap, fl_modif_t modif)
{
    unsigned long long nb = parse_typeu(ap, &modif);

    if (modif.zero) {
        return (ldprint_loop(fd, '0', modif.padding_left) +
            ldprint_loop(fd, '0', modif.precision) +
            ldputnbr_base(fd, nb, 8, 0));
    }
    return (ldprint_loop(fd, ' ', modif.padding_left) +
        ldprint_loop(fd, '0', modif.precision) +
        ldputnbr_base(fd, nb, 8, 0) +
        ldprint_loop(fd, ' ', modif.padding_right));
}
