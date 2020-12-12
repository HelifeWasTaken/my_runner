/*
** EPITECH PROJECT, 2020
** my_printf_header_file
** File description:
** structure_and_functions
*/

#ifndef __MY_PRINTF__H__
#define __MY_PRINTF__H__

#include <stdarg.h>
#include <stdbool.h>

typedef struct my_printf_flag_modification_struct {
    char *last_flag;
    bool zero;
    bool found_precision;
    bool default_precision;
    int space_padding;
    int precision;
    int offset;
    int already_printed;
    int fd;
} flag_modifiers_t;

typedef struct my_printf_function_redirect {
    char *flag;
    int (*flag_function)(va_list *arg, flag_modifiers_t modification_flag);
} my_printf_flags_t;

int my_printf(char const *str, ...);
int my_dprintf(int fd, char const *str, ...);
int my_dprintf_parser(int fd, char const **str, va_list *arg);
int my_dprintf_exception(char const **str, flag_modifiers_t modification_flag);
void get_modification_flag(char const **str,
        flag_modifiers_t *flag_modificater, int fd);

int my_vn_get_send_to_stdio(va_list *arg, int count_char);
int my_vn_putchar(va_list *arg, flag_modifiers_t modification_flag);
int my_vn_putstr(va_list *arg, flag_modifiers_t modification_flag);
int my_vn_putnbr(va_list *arg, flag_modifiers_t modification_flag);
int my_vn_putstr(va_list *arg, flag_modifiers_t modification_flag);
int my_vn_puthex_lower(va_list *arg, flag_modifiers_t flag_modificater);
int my_vn_puthex_upper(va_list *arg, flag_modifiers_t flag_modificater);
int my_vn_putbin(va_list *arg, flag_modifiers_t modification_flag);
int my_vn_putoct(va_list *arg, flag_modifiers_t modification_flag);
int my_vn_putpointer(va_list *arg, flag_modifiers_t modification_flag);
int my_vn_showstr_oct(va_list *arg, flag_modifiers_t modification_flag);
int my_vn_putunsigned(va_list *arg, flag_modifiers_t modification_flag);
int my_vn_putfloat(va_list *arg, flag_modifiers_t modification_flag);

#endif
