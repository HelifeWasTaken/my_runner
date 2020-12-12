/*
** EPITECH PROJECT, 2020
** lmath
** File description:
** lodeus_lib
*/

#pragma once

#ifndef __LODEUS__MATH__H__
#define __LODEUS__MATH__H__
#include <lodeus/ctypes.h>
#ifndef ABS
#define ABS(x) (x < 0) ? -x : x
#endif
unsigned long long lpow(unsigned long long x, int powto);
unsigned long long lsqrt(unsigned long long x);
char lfmod(double x, unsigned char y);
#ifdef __USE__FAIL__
double loderound(double nb, unsigned char precision);
#endif
#ifndef __LODEUS__NB__LEN__H__
#define __LODEUS__NB__LEN__H__
size_t lnblen(long long nb);
size_t lnbulen(unsigned long long nb);
size_t lnbbaselen(unsigned long long nb, int bas);
#endif
#endif

