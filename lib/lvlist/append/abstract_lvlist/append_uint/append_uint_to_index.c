/*
** EPITECH PROJECT, 2020
** append_uint_to_index.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void append_uint_lvlist_index(lvlist_t **head, uint64_t data, size_t index)
{
    lvlist_append_to_index(head, (void *)data, UINT_LIST, index);
}
