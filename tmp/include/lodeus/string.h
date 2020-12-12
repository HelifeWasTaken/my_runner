/*
** EPITECH PROJECT, 2020
** lstring
** File description:
** lodeus_lib
*/

#pragma once

#ifndef __LODEUS__STRING__H__
#define __LODEUS__STRING__H__
#include <lodeus/ctypes.h>
size_t lstrlen(char const *str);
#ifndef __LODEUS__MEM__H__
#define __LODEUS__MEM__H__
int lmemcmp(const void *s1, const void *s2, size_t n);
void *lmemmove(void *dest, const void *src, size_t n);
void *lmemset(void *s, int c, size_t n);
void *lmemcpy(void *dest, const void *src, size_t n);
#endif
char *lstrcat(char *dest, char *src);
char *lstrncat(char *dest, char const *src, const size_t n);
int lstrcmp(char const *s1, char const *s2);
int lstrncmp(char const *s1, char const *s2, size_t n);
char *lrevstr(char *str);
char *lstrcpy(char const *dest, char const *src);
char *lstrncpy(char const *dest, char const *src, size_t n);
char *lstrstr(char *haystack, const char *needle);
char *lstrdup(char const *str);
char *lstrndup(char const *str, size_t n);
char *lstrchr(const char *str, int c);
char **lsplit(char const *str, int separator);
void freelsplit(char **buffer);
char *lstr_realocat(char *s1, char *s2);
char *lstr_replace(char *dest, char *find, char *replace);
size_t lprint_loop(int c, size_t count);
#ifndef __LODEUS__NB__LEN__H__
#define __LODEUS__NB__LEN__H__
size_t lnblen(long long nb);
size_t lnbulen(long long nb);
size_t lnbbaselen(long long nb, int base);
#endif
#endif

