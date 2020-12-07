/*
** EPITECH PROJECT, 2020
** append_int_to_index.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void append_int_lvlist_index(lvlist_t **head, int64_t data, size_t index)
{
    lvlist_append_to_index(head, (void *)data, INT_LIST, index);
}
