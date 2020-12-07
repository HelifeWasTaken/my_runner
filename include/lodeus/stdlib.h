/*
** EPITECH PROJECT, 2020
** lstdlib
** File description:
** lodeus_lib
*/

#pragma once

#ifndef __LODEUS__STDLIB__H__
#define __LODEUX__STDLIB__H__
#include <lodeus/ctypes.h>
double latof(char const *str);
int latoi(char const *str);
long latol(char const *str);
long long latoll(char const *str);
void litoa(long long nb, char *buffer, char *base);
#ifndef __LODEUS__MEM__H__
#define __LODEUS__MEM__H__
int lmemcmp(const void *s1, const void *s2, size_t n);
void *lmemmove(void *dest, const void *src, size_t n);
void *lmemset(void *s, int c, size_t n);
void *lmemcpy(void *dest, const void *src, size_t n);
#endif
void *lcalloc(size_t nmemb, size_t size);
void *lrealloc(void *old_ptr, size_t old_size, size_t new_size);
void lptr_swap(void **ptr1, void **ptr2);
void lswap(int *a, int *b);
size_t lshow_ptr(long long ptr_value);
void lbzero(void *data, size_t size);
#endif

