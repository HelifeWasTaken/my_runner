/*
** EPITECH PROJECT, 2020
** lasprintf
** File description:
** lodeus_lib
*/

#include <stdarg.h>

size_t lasprintf(char *str, char const *format, ...)
{
    va_list ap;
    size_t done = 0;

    str = malloc(sizeof(char) * 16);
    if (!lprint_check_error_format(format))
        return (-1);
    va_start(ap, format);
    done = lvasprintf(format, ap);
    va_end(ap);
    return (done);
}

