/*
** EPITECH PROJECT, 2020
** append_str_to_tail.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void append_str_lvlist_tail(lvlist_t **head, char *data)
{
    lvlist_append_to_tail(head, (void *)data, STR_LIST);
}
