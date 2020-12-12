/*
** EPITECH PROJECT, 2020
** get_modification_flag
** File description:
** get_modification
*/

#include <my_printf.h>
#include <my_math.h>
#include <my_str.h>
#include <stdbool.h>
#include <my_stdlib.h>
#include <my_stdio.h>

/*
**
** This is a simple switch permitting me to turn on the flags encountered
**
*/

static bool get_the_flag(char const c, flag_modifiers_t *flag_modificater)
{
    switch (c) {
        case '0':
            flag_modificater->zero = true;
            return (true);
        case ' ':
            return (true);
        default:
            return (false);
    }
}

/*
**
** A simple function to be clean while using the structure
** To be sure that everything is setted to zero
**
*/

static void intialize_struct_to_zero(flag_modifiers_t *flag_modificater, int fd)
{
    flag_modificater->last_flag = NULL;
    flag_modificater->zero = false;
    flag_modificater->found_precision = false;
    flag_modificater->default_precision = true;
    flag_modificater->space_padding = 0;
    flag_modificater->precision = 0;
    flag_modificater->offset = 0;
    flag_modificater->already_printed = 0;
    flag_modificater->fd = fd;
}

/*
**
** This is called when '.' is found while searching for the flags modificater
** It basically gets if the default precision should be used or
** If you should use a precision explicitely given
**
*/

static void get_precision(char const **str, flag_modifiers_t *flag_modificater)
{
    (flag_modificater->offset)++;
    flag_modificater->found_precision = true;
    if (is_num_letter(*(*str + flag_modificater->offset))) {
        flag_modificater->precision =
            my_getnbr(*str + flag_modificater->offset);
        flag_modificater->offset +=
            get_nb_size(flag_modificater->precision, 10);
    } else {
        flag_modificater->precision = 1;
        flag_modificater->default_precision = true;
    }
}

/*
**
** This is the function parsing the whole modification and making the calls
** to the functions seen above
**
** It calculate the offset in real time
**
*/

void get_modification_flag(char const **str, flag_modifiers_t *flag_modificater,
        int fd)
{
    intialize_struct_to_zero(flag_modificater, fd);
    while ((**str) + flag_modificater->offset &&
            get_the_flag(*(*str + flag_modificater->offset), flag_modificater))
        (flag_modificater->offset)++;
    if (is_num_letter(*(*str + flag_modificater->offset))) {
        flag_modificater->space_padding =
            my_getnbr(*str + flag_modificater->offset);
        flag_modificater->offset +=
            get_nb_size(flag_modificater->space_padding, 10);
    }
    if (*(*str + flag_modificater->offset) == '.')
        get_precision(str, flag_modificater);
}