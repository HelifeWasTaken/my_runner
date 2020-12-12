/*
** EPITECH PROJECT, 2020
** parse_type
** File description:
** lodeus_lib
*/

#include <lodeus/lvprintf/flag_modif.h>
#include <stdarg.h>

long long parse_typeu(va_list *ap, struct flag_modifiers *modif)
{
    switch (modif->lenmodifier) {
        case LPRINTF_MOD_CHAR:
            return ((unsigned char)va_arg(*ap, unsigned int));
        case LPRINTF_MOD_SHORT:
            return ((unsigned short int)va_arg(*ap, unsigned int));
        case LPRINTF_MOD_LONG:
            return ((unsigned long)va_arg(*ap, unsigned long));
        case LPRINTF_MOD_LONG_LONG:
            return ((unsigned long long)va_arg(*ap, unsigned long long));
        case LPRINTF_MOD_INT_MAX:
            return ((intmax_t)va_arg(*ap, intmax_t));
        case LPRINTF_MOD_SIZE_T:
            return ((size_t)va_arg(*ap, size_t));
        case LPRINTF_MOD_PTRDIFF:
            return ((ptrdiff_t)va_arg(*ap, ptrdiff_t));
        default:
            return ((unsigned int)va_arg(*ap, unsigned int));
    }
}

long long parse_type(va_list *ap, struct flag_modifiers *modif)
{
    switch (modif->lenmodifier) {
        case LPRINTF_MOD_CHAR:
            return ((char)va_arg(*ap, int));
        case LPRINTF_MOD_SHORT:
            return ((short int)va_arg(*ap, int));
        case LPRINTF_MOD_LONG:
            return ((long)va_arg(*ap, long));
        case LPRINTF_MOD_LONG_LONG:
            return ((long long)va_arg(*ap, long long));
        case LPRINTF_MOD_INT_MAX:
            return ((intmax_t)va_arg(*ap, intmax_t));
        case LPRINTF_MOD_SIZE_T:
            return ((size_t)va_arg(*ap, size_t));
        case LPRINTF_MOD_PTRDIFF:
            return ((ptrdiff_t)va_arg(*ap, ptrdiff_t));
        default:
            return ((int)va_arg(*ap, int));
    }
}
