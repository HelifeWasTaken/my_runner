/*
** EPITECH PROJECT, 2020
** display_first_uint.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void display_first_uint_occurence(lvlist_t *head)
{
    if (!head) {
        lprintf("List empty");
        return;
    }
    for (; head; head = head->next) {
        if (head->type == UINT_LIST) {
            lprintf("%llu", (unsigned long long)head->data);
            return;
        }
    }
    lprintf("NULL");
}
