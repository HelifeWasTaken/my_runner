/*
** EPITECH PROJECT, 2020
** append_str_to_index.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void append_str_lvlist_index(lvlist_t **head, char *data, size_t index)
{
    lvlist_append_to_index(head, (void *)data, STR_LIST, index);
}
