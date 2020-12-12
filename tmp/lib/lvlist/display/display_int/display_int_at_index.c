/*
** EPITECH PROJECT, 2020
** display_int_at_index.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void display_int_at_index(lvlist_t *head, size_t index)
{
    size_t i;

    if (!head) {
        lprintf("HEAD - NULL");
        return;
    }
    for (i = 0; head && i < index; i++)
        head = head->next;
    if (!head) {
        lprintf("END - NULL - %lu", i);
        return;
    }
    if (head->type != INT_LIST) {
        lprintf("Wrong type - %lu - ", i);
        display_lvlist_type(head->type);
        return;
    }
    else
        lprintf("%lld", (long long)head->data);
}
