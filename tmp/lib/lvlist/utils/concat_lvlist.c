/*
** EPITECH PROJECT, 2020
** concat_lvlist.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void concat_lvlist(lvlist_t **dest, lvlist_t *src)
{
    lvlist_t *dest_ptr = *dest;

    if (!dest_ptr)
        *dest = src;
    for (; dest_ptr->next; dest_ptr = dest_ptr->next);
    dest_ptr->next = src;
}
