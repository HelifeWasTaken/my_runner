/*
** EPITECH PROJECT, 2020
** display_last_uint.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void display_last_uint_occurence(lvlist_t *head)
{
    uint64_t value;

    if (!head) {
        lprintf("List empty");
        return;
    }
    for (; head; head = head->next) {
        if (head->type == UINT_LIST) {
            value = (long long)head->data;
        }
    }
    if (!value)
        lprintf("NULL");
    else
        lprintf("%lu", value);
}
