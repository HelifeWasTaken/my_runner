/*
** EPITECH PROJECT, 2020
** display_str.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void dump_display_str(lvlist_t *head, size_t index)
{
    lprintf("List n°%lu : %s - str\n", index, (char *)head->data);
}
