/*
** EPITECH PROJECT, 2020
** display_all_int.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void display_all_int_occurence(lvlist_t *head)
{
    bool found_an_int = false;

    if (!head) {
        lprintf("List empty");
        return;
    }
    for (; head; head = head->next) {
        if (head->type == INT_LIST) {
            lprintf("%lld\n", (long long)head->data);
            found_an_int = true;
        }
    }
    if (!found_an_int)
        lprintf("NULL");
}
