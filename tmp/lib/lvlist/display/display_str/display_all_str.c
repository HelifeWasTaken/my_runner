/*
** EPITECH PROJECT, 2020
** display_all_str.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void display_all_str_occurence(lvlist_t *head)
{
    bool found_an_str = false;

    if (!head) {
        lprintf("List empty");
        return;
    }
    for (; head; head = head->next) {
        if (head->type == STR_LIST) {
            lprintf("%s\n", (char *)head->data);
            found_an_str = true;
        }
    }
    if (!found_an_str)
        lprintf("NULL");
}
