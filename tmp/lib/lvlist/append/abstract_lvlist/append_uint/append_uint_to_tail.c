/*
** EPITECH PROJECT, 2020
** append_uint_to_tail.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void append_uint_lvlist_tail(lvlist_t **head, uint64_t data)
{
    lvlist_append_to_tail(head, (void *)data, UINT_LIST);
}
