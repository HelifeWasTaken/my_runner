/*
** EPITECH PROJECT, 2020
** lprintf_flag_character
** File description:
** lodeus_lib
*/

#include <lodeus/lvprintf/flag_modif.h>
#include <lodeus/string.h>
#include <lodeus/stdlib.h>
#include <lodeus/stdio.h>

static bool check_character(struct flag_modifiers *modif, char const c)
{
    switch (c) {
        case '0':
            modif->zero = true;
            return (true);
        case '-':
            modif->minus = true;
            return (true);
        default:
            return (false);
    }
}

static void get_len_modifier(struct flag_modifiers *modif,
    char const **format)
{
    if (lisnum(*(*format + modif->offset))) {
        modif->padding_left = latoi(*format + modif->offset);
        modif->offset += lnblen(modif->padding_left);
    }
    if (*(*format + modif->offset) == '.') {
        modif->offset += 1;
        modif->precision = latoi(*format + modif->offset);
        modif->offset = lnblen(modif->precision);
    }
}

static void turn_off_unlogic(struct flag_modifiers *modif)
{
    if (modif->zero && modif->minus)
        modif->zero = false;
    if (modif->foundprecision) {
        modif->padding_left =
            (modif->padding_left - modif->precision >= 0) ?
            modif->padding_left - modif->precision : 0;
    }
    if (modif->minus)
        lswap(&modif->padding_right, &modif->padding_left);

}

fl_modif_t get_lprintf_flag_character(char const **format)
{
    struct flag_modifiers modif = {0, 0, 0, 0, 0, 0, 0, 0};

    while (check_character(&modif, *(*format) + modif.offset))
        modif.offset++;
    get_len_modifier(&modif, format);
    turn_off_unlogic(&modif);
    lprintf_lenght_modifiers(&modif, format);
    return (modif);
}

