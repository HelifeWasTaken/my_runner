/*
** EPITECH PROJECT, 2020
** display_first_str.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void display_first_str_occurence(lvlist_t *head)
{
    if (!head) {
        lprintf("List empty");
        return;
    }
    for (; head; head = head->next) {
        if (head->type == STR_LIST) {
            lprintf("%s", (char *)head->data);
            return;
        }
    }
    lprintf("NULL");
}
