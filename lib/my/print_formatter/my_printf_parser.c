/*
** EPITECH PROJECT, 2020
** my_printf_parser
** File description:
** my_printf_parser
*/

#include <my_printf.h>
#include <stddef.h>
#include <stdarg.h>
#include <my_str.h>
#include <my_stdio.h>

static const my_printf_flags_t arrays_flags[36] = {
    { "d", &my_vn_putnbr },
    { "i", &my_vn_putnbr },
    { "s", &my_vn_putstr },
    { "c", &my_vn_putchar },
    { "x", &my_vn_puthex_lower },
    { "X", &my_vn_puthex_upper },
    { "b", &my_vn_putbin },
    { "o", &my_vn_putoct },
    { "p", &my_vn_putpointer },
    { "u", &my_vn_putunsigned },
    { "ld", &my_vn_putnbr },
    { "li", &my_vn_putnbr },
    { "lu", &my_vn_putunsigned },
    { "lx", &my_vn_puthex_lower },
    { "lX", &my_vn_puthex_lower },
    { "lld", &my_vn_putnbr },
    { "lli", &my_vn_putnbr },
    { "llu", &my_vn_putunsigned },
    { "llx", &my_vn_puthex_lower },
    { "llX", &my_vn_puthex_upper },
    { "qd", &my_vn_putnbr },
    { "qi", &my_vn_putnbr },
    { "qu", &my_vn_putunsigned },
    { "qx", &my_vn_puthex_lower },
    { "qX", &my_vn_puthex_upper },
    { "hhd", &my_vn_putnbr },
    { "hhi", &my_vn_putnbr },
    { "hhu", &my_vn_putunsigned },
    { "hhx", &my_vn_puthex_lower },
    { "hhX", &my_vn_puthex_upper },
    { "hd", &my_vn_putnbr },
    { "hi", &my_vn_putnbr },
    { "hu", &my_vn_putunsigned },
    { "hx", &my_vn_puthex_lower },
    { "hX", &my_vn_puthex_upper },
    { NULL, 0 }
};

int my_dprintf_exception(char const **str, flag_modifiers_t modification_flag)
{
    int i = 0;

    for (i = 0; i < modification_flag.offset; i++)
        fd_putchar(modification_flag.fd, *(*str)++);
    if (*str)
        return (fd_putchar(modification_flag.fd, *(*str++) + i));
    return (i);
}

int my_dprintf_parser(int fd, char const **str, va_list *arg)
{
    flag_modifiers_t modification_flag;
    int (*my_printf_call)(va_list *arg, flag_modifiers_t);

    get_modification_flag(str, &modification_flag, fd);
    for (int i = 0; arrays_flags[i].flag != NULL; i++) {
        modification_flag.last_flag = arrays_flags[i].flag;
        if (my_strncmp(*str + modification_flag.offset,
                    modification_flag.last_flag,
                    my_strlen(modification_flag.last_flag)) == 0) {
            my_printf_call = arrays_flags[i].flag_function;
            break;
        }
    }
    if (!my_printf_call)
        return (my_dprintf_exception(str, modification_flag));
    *str += my_strlen(modification_flag.last_flag) + modification_flag.offset;
    return (my_printf_call(arg, modification_flag));
}