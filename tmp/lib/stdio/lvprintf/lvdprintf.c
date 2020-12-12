/*
** EPITECH PROJECT, 2020
** lvprintf
** File description:
** lodeus_lib
*/

#include <lodeus/stdio.h>
#include <lodeus/fd.h>

size_t lvdprintf(int fd, char const *format, va_list *ap)
{
    int count = 0;

    while (*format) {
        if (*format == '%' && *format + 1 != '%') {
            format++;
            count += parser_lvdprintf(fd, &format, ap);
        }
        else if (*format == '%' && *format + 1 == '%') {
            count += ldputchar(fd, '%');
            format += 2;
        }
        else
            count += ldputchar(fd, *format++);
    }
    return (count);
}

