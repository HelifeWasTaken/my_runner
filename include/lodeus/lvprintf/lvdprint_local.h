/*
** EPITECH PROJECT, 2020
** lvdprintf_local
** File description:
** lodeus_lib
*/

#ifndef __LODEUS__LVDPRINTF__LOCAL__H__
#define __LODEUS__LVDPRINTF__LOCAL__H__
#include <lodeus/lvprintf/flag_modif.h>
#include <stdarg.h>
    size_t lvdprintf_local_char(int fd, va_list *ap, fl_modif_t modif);
    size_t lvdprintf_local_int(int fd, va_list *ap, fl_modif_t modif);
    size_t lvdprintf_local_str(int fd, va_list *ap, fl_modif_t modif);
    size_t lvdprintf_local_oct(int fd, va_list *ap, fl_modif_t modif);
    size_t lvdprintf_local_uint(int fd, va_list *ap, fl_modif_t modif);
    size_t lvdprintf_local_hexmin(int fd, va_list *ap, fl_modif_t modif);
    size_t lvdprintf_local_hexmax(int fd, va_list *ap, fl_modif_t modif);
    size_t lvdprintf_local_pointer(int fd, va_list *ap, fl_modif_t modif);
    size_t lvdprintf_local_float(int fd, va_list *ap, fl_modif_t modif);
#endif

