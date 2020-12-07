/*
** EPITECH PROJECT, 2020
** append_int_to_head.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void append_int_lvlist_head(lvlist_t **head, int64_t data)
{
    lvlist_append_to_head(head, (void *)data, INT_LIST);
}
