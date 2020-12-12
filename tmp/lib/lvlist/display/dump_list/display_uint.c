/*
** EPITECH PROJECT, 2020
** display_uint.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void dump_display_uint(lvlist_t *head, size_t index)
{
    lprintf("List n°%lu : %lu - uint\n", index, (uint64_t)head->data);
}
