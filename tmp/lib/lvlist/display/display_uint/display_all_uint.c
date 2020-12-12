/*
** EPITECH PROJECT, 2020
** display_all_uint.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void display_all_uint_occurence(lvlist_t *head)
{
    bool found_an_uint = false;

    if (!head) {
        lprintf("List empty");
        return;
    }
    for (; head; head = head->next) {
        if (head->type == UINT_LIST) {
            lprintf("%llu\n", (unsigned long long)head->data);
            found_an_uint = true;
        }
    }
    if (!found_an_uint)
        lprintf("NULL");
}
