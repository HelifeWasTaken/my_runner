/*
** EPITECH PROJECT, 2020
** display_int.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void dump_display_int(lvlist_t *head, size_t index)
{
    lprintf("List n°%lu : %ld - int\n", index, (int64_t)head->data);
}
