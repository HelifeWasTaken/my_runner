/*
** EPITECH PROJECT, 2020
** lprintf_lenght_modifiers
** File description:
** lodeus_lib
*/

#include <lodeus/lvprintf/flag_modif.h>
#include <lodeus/string.h>

void lprintf_lenght_modifiers(fl_modif_t *modif, char const **format)
{
    char know_flag[9][2] = {"hh", "h", "ll", "l", "q", "j", "z", "Z", "t"};
    unsigned char len_flags[9] = {2, 1, 2, 1, 1, 1, 1, 1, 1};
    unsigned char state_flag[9] = {LPRINTF_MOD_CHAR, LPRINTF_MOD_SHORT,
        LPRINTF_MOD_LONG_LONG, LPRINTF_MOD_LONG, LPRINTF_MOD_LONG_LONG,
        LPRINTF_MOD_INT_MAX, LPRINTF_MOD_SIZE_T, LPRINTF_MOD_SIZE_T,
        LPRINTF_MOD_PTRDIFF};

    for (unsigned char i = 0; i < 8; i++) {
        if (!lstrncmp(know_flag[i], (*format) + modif->offset, len_flags[i])) {
            modif->lenmodifier = state_flag[i];
            modif->offset += len_flags[i];
            return;
        }
    }
    modif->lenmodifier = LPRINTF_MOD_NONE;
}

