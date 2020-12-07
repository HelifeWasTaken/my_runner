/*
** EPITECH PROJECT, 2020
** append_uint_to_head.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void append_uint_lvlist_head(lvlist_t **head, uint64_t data)
{
    lvlist_append_to_head(head, (void *)data, UINT_LIST);
}
