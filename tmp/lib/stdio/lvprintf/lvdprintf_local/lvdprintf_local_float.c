/*
** EPITECH PROJECT, 2020
** lvdprintf_local_float
** File description:
** lodeus_lib
*/

#include <lodeus/fd.h>
#include <lodeus/lvprintf/flag_modif.h>
#include <stdarg.h>

size_t lvdprintf_local_float(int fd, va_list *ap, fl_modif_t modif)
{
    double nb = va_arg(*ap, double);

    if (!modif.foundprecision)
        modif.precision = 6;
    return (ldputfloat(fd, nb, modif.precision));
}

