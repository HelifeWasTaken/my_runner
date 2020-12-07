/*
** EPITECH PROJECT, 2020
** ldprintf
** File description:
** lodeus_lib
*/

#include <lodeus/stdio.h>
#include <stdarg.h>

size_t ldprintf(int fd, char const *format, ...)
{
    va_list ap;
    size_t done = 0;

    if (!lprint_check_error_format(format))
        return (-1);
    va_start(ap, format);
    done = lvdprintf(fd, format, &ap);
    va_end(ap);
    return (done);
}
