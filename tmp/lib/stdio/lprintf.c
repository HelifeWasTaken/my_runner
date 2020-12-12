/*
** EPITECH PROJECT, 2020
** lprintf
** File description:
** lodeus_lib
*/

#include <lodeus/stdio.h>

size_t lprintf(char const *format, ...)
{
    va_list ap;
    size_t done = 0;

    if (!lprint_check_error_format(format))
        return (-1);
    va_start(ap, format);
    done = lvdprintf(STDOUT_FILENO, format, &ap);
    va_end(ap);
    return (done);
}
