/*
** EPITECH PROJECT, 2020
** lvdprintf_local_str
** File description:
** lodeus_lib
*/

#include <unistd.h>
#include <lodeus/fd.h>
#include <lodeus/string.h>
#include <lodeus/lvprintf/flag_modif.h>
#include <lodeus/lvprintf/lvdprint_local.h>

size_t lvdprintf_local_str(int fd, va_list *ap, fl_modif_t modif)
{
    char *str = va_arg(*ap, char *);

    if (!str)
        write(1, "(null)", 6);
    return (ldprint_loop(fd, ' ', modif.padding_left) +
        write(fd, str, lstrlen(str)) +
        ldprint_loop(fd, ' ', modif.padding_right));
}
