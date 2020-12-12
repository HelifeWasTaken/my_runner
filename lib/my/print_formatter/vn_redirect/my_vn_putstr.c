/*
** EPITECH PROJECT, 2020
** my_vn_putstr
** File description:
** redirect_for_my_putstr
*/

#include <unistd.h>
#include <stdarg.h>
#include <my_printf.h>

size_t my_strlen(char const *str);

size_t fd_print_char_in_loop(int fd, int count, char c);

int my_vn_putstr(va_list *arg, flag_modifiers_t flag_modificater)
{
    char *str = va_arg(*arg, char *);
    int real_padding = (flag_modificater.space_padding - my_strlen(str) > 0) ?
        flag_modificater.space_padding - my_strlen(str) : 0;

    return (fd_print_char_in_loop(flag_modificater.fd, real_padding, ' ') +
            write(flag_modificater.fd, str, my_strlen(str)));
}
