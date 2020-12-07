/*
** EPITECH PROJECT, 2020
** parse_flag
** File description:
** lodeus_lib
*/

#include <lodeus/stdio.h>
#include <stdarg.h>
#include <lodeus/lvprintf/flag_modif.h>
#include <lodeus/lvprintf/lvdprint_local.h>

static const lvdprintf_flag_t lvdprintf_flag[10] = {
    {'c', &lvdprintf_local_char},
    {'s', &lvdprintf_local_str},
    {'d', &lvdprintf_local_int},
    {'i', &lvdprintf_local_int},
    {'f', &lvdprintf_local_float},
    {'u', &lvdprintf_local_uint},
    {'o', &lvdprintf_local_oct},
    {'x', &lvdprintf_local_hexmin},
    {'X', &lvdprintf_local_hexmax},
    {'p', &lvdprintf_local_pointer},
};

size_t parser_lvdprintf(int fd, char const **format, va_list *ap)
{
    fl_modif_t modif = get_lprintf_flag_character(format);

    for (size_t i = 0; i < 10; i++) {
        if (*(*format + modif.offset) == lvdprintf_flag[i].flag) {
            *format += modif.offset + 1;
            return ((*lvdprintf_flag[i].ptrf)(fd, ap, modif));
        }
    }
    *format += modif.offset;
    return (-1);
}

/*
void parse_lsprintf(char **buffer, char **format, va_list *ap,
        lsprintf_conversion_t *convert)
{
}
*/
