/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdbool.h>
#include <my_stdio.h>
#include <my_printf.h>

static bool check_for_basic_error(char const *str, va_list *arg)
{
    int found_twice = false;

    for (int i = 0; str[i]; i++) {
        if ((str[i] != ' ' && str[i] != '%') || found_twice == 2)
            return (true);
        if (str[i] == '%')
            found_twice++;
    }
    if (found_twice == 2)
        return (true);
    va_end(*arg);
    return (false);
}

int my_vdprintf(int fd, char const *str, va_list *arg)
{
    int count = 0;

    if (!check_for_basic_error(str, arg))
        return (-1);
    while (*str) {
        if (*str == '%' && *str + 1 != '%') {
            str++;
            count += my_dprintf_parser(fd, &str, arg);
        }
        else if (*str == '%' && *str + 1 == '%') {
            count += fd_putchar(fd, '%');
            str += 2;
        }
        else
            count += fd_putchar(fd, *(str++));
    }
    va_end(*arg);
    return (count);
}

int my_dprintf(int fd, char const *str, ...)
{
    va_list arg;

    va_start(arg, str);
    return (my_vdprintf(fd, str, &arg));
}

int my_printf(char const *str, ...)
{
    va_list arg;

    va_start(arg, str);
    return (my_vdprintf(1, str, &arg));
}
