/*
** EPITECH PROJECT, 2020
** display_first_int.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void display_first_int_occurence(lvlist_t *head)
{
    if (!head) {
        lprintf("List empty");
        return;
    }
    for (; head; head = head->next) {
        if (head->type == INT_LIST) {
            lprintf("%lld", (long long)head->data);
            return;
        }
    }
    lprintf("NULL");
}
