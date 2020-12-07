/*
** EPITECH PROJECT, 2020
** lvlist
** File description:
** lodeus
*/

#pragma once

#ifndef __LODEUS__VARIADIC_LINKED_LIST__H__
#define __LODEUS__VARIADIC_LINKED_LIST__H__
#include <lodeus/ctypes.h>
#include <lodeus/stdio.h>
#include <stdlib.h>
#include <stdbool.h>
enum {
    INT_LIST,
    UINT_LIST,
    STR_LIST,
    END_LIST
};

typedef struct lvlist {
    void *data;
    uint8_t type;
    struct lvlist *next;
    struct lvlist *prev;
} lvlist_t;

lvlist_t *add_lvlist_node(void *data, unsigned int type);
void concat_lvlist(lvlist_t **dest, lvlist_t *src);
size_t count_lvlist_node(lvlist_t *head);
void reverse_lvlist(lvlist_t **head);

void lvlist_append_to_head(lvlist_t **head, void *data, unsigned int type);
void lvlist_append_to_tail(lvlist_t **head, void *data, unsigned int type);
void lvlist_append_to_index(lvlist_t **head, void *data, unsigned int type,
        size_t index);

void append_int_lvlist_tail(lvlist_t **head, int64_t data);
void append_int_lvlist_head(lvlist_t **head, int64_t data);
void append_int_lvlist_index(lvlist_t **head, int64_t data, size_t index);

void append_uint_lvlist_tail(lvlist_t **head, uint64_t data);
void append_uint_lvlist_head(lvlist_t **head, uint64_t data);
void append_uint_lvlist_index(lvlist_t **head, uint64_t data, size_t index);

void append_str_lvlist_tail(lvlist_t **head, char *data);
void append_str_lvlist_head(lvlist_t **head, char *data);
void append_str_lvlist_index(lvlist_t **head, char *data, size_t index);

void display_lvlist_type(unsigned int type_value);

void dump_lvlist(lvlist_t *head);
void dump_lvlist_reverse(lvlist_t *head);
void dump_display_int(lvlist_t *head, size_t index);
void dump_display_uint(lvlist_t *head, size_t index);
void dump_display_str(lvlist_t *head, size_t index);

void display_all_str_occurence(lvlist_t *head);
void display_first_str_occurence(lvlist_t *head);
void display_last_str_occurence(lvlist_t *head);
void display_str_at_index(lvlist_t *head, size_t index);

void display_all_int_occurence(lvlist_t *head);
void display_first_int_occurence(lvlist_t *head);
void display_last_int_occurence(lvlist_t *head);
void display_int_at_index(lvlist_t *head, size_t index);

void display_all_uint_occurence(lvlist_t *head);
void display_first_uint_occurence(lvlist_t *head);
void display_last_uint_occurence(lvlist_t *head);
void display_uint_at_index(lvlist_t *head, size_t index);

char *get_lvlist_next_str_occurence(lvlist_t **head, bool popit);
int64_t get_lvlist_next_int_occurence(lvlist_t **head, bool popit);
uint64_t get_lvlist_next_uint_occurence(lvlist_t **head, bool popit);
void *get_lvlist_at_index(lvlist_t **head, size_t i, bool popit);

void remove_lvlist_at_index(lvlist_t **head, size_t index);
void remove_lvlist_head(lvlist_t **head);
void remove_lvlist_tail(lvlist_t **head);

int64_t cast_lvlist_to_int(void *data);
uint64_t cast_lvlist_to_uint(void *data);
char *cast_lvlist_to_str(void *data);

#define APPEND_LVLIST_HEAD(list, x) _Generic((x), \
    int: append_int_lvlist_head, \
    long : append_int_lvlist_head, \
    long long: append_int_lvlist_head, \
    unsigned int: append_uint_lvlist_head, \
    unsigned long: append_uint_lvlist_head, \
    unsigned long long: append_uint_lvlist_head, \
    char *: append_str_lvlist_head, \
    const char *: append_str_lvlist_head) \
    (list, x)

#define APPEND_LVLIST_TAIL(list, x) _Generic((x), \
    int: append_int_lvlist_tail, \
    long: append_int_lvlist_tail, \
    long long: append_int_lvlist_tail, \
    unsigned int: append_uint_lvlist_tail, \
    unsigned long: append_uint_lvlist_tail, \
    unsigned long long: append_uint_lvlist_tail, \
    char *: append_str_lvlist_tail, \
    const char *: append_str_lvlist_tail) \
    (list, x)

#define APPEND_LVLIST_AT_INDEX(list, x, i) _Generic((x), \
    int: append_int_lvlist_index, \
    long: append_int_lvlist_index, \
    long long: append_int_lvlist_index, \
    unsigned int: append_uint_lvlist_index, \
    unsigned long: append_uint_lvlist_index, \
    unsigned long long: append_uint_lvlist_index, \
    char *: append_str_lvlist_index, \
    const char *: append_str_lvlist_index) \
    (list, x, i)

#define GET_LVLIST_AT_INDEX(type, list, x, i) _Generic((type), \
    int: cast_lvlist_to_int, \
    long: cast_lvlist_to_int, \
    long long: cast_lvlist_to_int, \
    unsigned int: cast_lvlist_to_uint, \
    unsigned long: cast_lvlist_to_uint, \
    unsigned long long: cast_lvlist_to_uint, \
    char *: cast_lvlist_to_str, \
    const char *: cast_lvlist_to_str) \
    (get_lvlist_at_index(list, x, i))
#define POP_IT true
#define KEEP_IT false
#endif
