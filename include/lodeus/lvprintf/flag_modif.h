/*
** EPITECH PROJECT, 2020
** flag_modif
** File description:
** lodeus_lib
*/

#pragma once

#ifndef __LODEUS__LPRINTF__FLAG__MODIF__H__
#define __LODEUS__LPRINTF__FLAG__MODIF__H__
#include <stdarg.h>
#include <lodeus/ctypes.h>
typedef struct flag_modifiers {
    int precision;
    int padding_right;
    int padding_left;
    unsigned char lenmodifier;
    bool foundprecision;
    bool zero;
    bool minus;
    size_t offset;
} fl_modif_t;

typedef enum {
    LPRINTF_MOD_CHAR,
    LPRINTF_MOD_SHORT,
    LPRINTF_MOD_LONG,
    LPRINTF_MOD_LONG_LONG,
    LPRINTF_MOD_SIZE_T,
    LPRINTF_MOD_INT_MAX,
    LPRINTF_MOD_PTRDIFF,
    LPRINTF_MOD_NONE
} len_modifier_t;

typedef struct lvsprintf_conversion {
    size_t actual_used_size;
    size_t usable_size;
    struct flag_modifiers modif;
} lsprintf_conversion_t;

typedef struct lvdprintf_flag {
    char flag;
    size_t(*ptrf)(int, va_list *, struct flag_modifiers);
} lvdprintf_flag_t;

typedef struct lvsprintf_flag {
    char flag;
    size_t(*ptrf)(int, va_list *, struct flag_modifiers);
} lvsprintf_flag_t;

fl_modif_t get_lprintf_flag_character(char const **format);
void lprintf_lenght_modifiers(fl_modif_t *modif, char const **format);
long long parse_typeu(va_list *ap, struct flag_modifiers *modif);
long long parse_type(va_list *ap, struct flag_modifiers *modif);
#endif

