/*
** EPITECH PROJECT, 2020
** display_last_int.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void display_last_int_occurence(lvlist_t *head)
{
    int64_t value;

    if (!head) {
        lprintf("List empty");
        return;
    }
    for (; head; head = head->next) {
        if (head->type == INT_LIST) {
            value = (long long)head->data;
        }
    }
    if (!value)
        lprintf("NULL");
    else
        lprintf("%ld", value);
}
