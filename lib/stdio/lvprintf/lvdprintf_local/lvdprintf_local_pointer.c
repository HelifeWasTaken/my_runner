/*
** EPITECH PROJECT, 2020
** lvdprintf_local_pointer
** File description:
** lodeus_lib
*/

#include <unistd.h>
#include <lodeus/fd.h>
#include <lodeus/lvprintf/flag_modif.h>

size_t lvdprintf_local_pointer(int fd, va_list *ap, fl_modif_t modif)
{
    long long nb = va_arg(*ap, long long);

    (void)modif;
    return (write(fd, "0x", 2) + ldputnbr_base(fd, nb, 16, 0));
}

