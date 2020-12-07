/*
** EPITECH PROJECT, 2020
** lprint_check_error_format
** File description:
** lodeus_lib
*/

#include <lodeus/ctypes.h>

bool lprint_check_error_format(char const *format)
{
    unsigned char found_twice = 0;

    for (size_t i = 0; format[i]; i++) {
        if ((format[i] != ' ' && format[i] != '%') || found_twice == 2)
            return (true);
        if (format[i] == '%')
            found_twice++;
    }
    if (found_twice == 2)
        return (true);
    return (false);
}
