/*
** EPITECH PROJECT, 2020
** append_str_to_head.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void append_str_lvlist_head(lvlist_t **head, char *data)
{
    lvlist_append_to_head(head, (void *)data, STR_LIST);
}
