/*
** EPITECH PROJECT, 2020
** lassert
** File description:
** lodeus_lib
*/

#pragma once

#ifndef __LODEUS__ASSERT__H__
#define __LODEUS__ASSERT__H__
    #include <lodeus/ctypes.h>
    #ifndef NO_USE
        #define NO_USE __attribute__((unused))
    #endif
    #define DOES_ADD_OVERFLOW(a, b) \
        __builtin_add_overflow_p(a, b, (__typeof__ ((a) + (b))) 0)
    #define DOES_SUB_OVERFLOW(a, b) \
        __builtin_sub_overflow_p(a, b, (__typeof__((a) + (b))) 0)
    #define DOES_MUL_OVERFLOW(a, b) \
        __builtin_mul_overflow_p(a, b, (__typeof__((a) + (b))) 0)
    #define LESS_SIGNIFICANT_BYTE(byte) ((byte) ^ ((byte) - 1) & (byte))
    #define ARRAY_SIZE(x) sizeof(x) / sizeof(*x)
    #define ABS(x) (x < 0) ? -x : x
    #define MAX(x, y) (x > y) ? x : y
    #define MIN(x, y) (x < y) ? x : y
    #define IS_ODD(x) x & 1
    #define IS_EVEN !(IS_ODD(x))
    #ifndef __LODEUS__RET__
        #define __LODEUS__RET__
        #define LODEUS_SUCESS 0
        #define LODEUS_FAIL 84
    #endif
    #ifdef EXIT_SUCESS
        #undef EXIT_SUCESS
    #endif
    #ifdef EXIT_FAILURE
        #undef EXIT_FAILURE
    #endif
    #define EXIT_SUCESS 0
    #define EXIT_FAILURE 84
    #define IS_BETWEEN(x, y, z) (x <= y && z >= y)
#endif
