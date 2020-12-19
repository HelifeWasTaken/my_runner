/*
** EPITECH PROJECT, 2020
** my_str_libmy
** File description:
** libmy_for_the_epitech_curriculum
*/

#pragma once

#ifndef _MY_STR_H_
    #define _MY_STR_H_
    #include <stdbool.h>
    #include <stddef.h>
    #include <sys/types.h>
    size_t print_char_in_loop(int const count, char const c);
    size_t fd_print_char_in_loop(int const fd, int const count, char const c);
    bool is_an_alpha_letter(char const c);
    bool is_capital_letter(char const c);
    bool is_lowercase_letter(char const c);
    bool is_num_letter(char const c);
    bool is_printable(char const c);
    bool is_char_alphanum(char const c);
    size_t my_len_array(size_t const nb_elements, char **array);
    char *my_put_in_str(char *str, ssize_t const index, char const to_add);
    char *my_revstr(char *str);
    size_t my_showstr(char const *str);
    size_t fd_showstr(const int fd, char const *str);
    char *my_strcat(char *dest, char const *src);
    char my_strcmp(char const *s1, char const *s2);
    char *my_strcpy(char *dest, char const *src);
    size_t my_strlen(char const *str);
    char *my_strncat(char *dest, char const *src, size_t const nb);
    int my_strncmp(char const *s1, char const *s2, size_t const n);
    char *my_strncpy(char *dest, char const *src, size_t const n);
    char *my_strstr(char *str, char const *to_find);
    int my_word_count(char const *str);
    size_t print_char_in_hex(unsigned char const c);
    size_t fd_print_char_in_hex(int const fd, unsigned char const c);
    size_t print_char_in_oct(unsigned char c);
    size_t fd_print_char_in_oct(int fd, unsigned char c);
    char *my_str_realocat(char *dest, char *src);
    char **split(char const *str, int separator);
    void freesplit(char **buffer);
    size_t count_split(char **buffer);
#endif
