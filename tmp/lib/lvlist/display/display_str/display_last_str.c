/*
** EPITECH PROJECT, 2020
** display_last_str.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void display_last_str_occurence(lvlist_t *head)
{
    char *str = NULL;

    if (!head) {
        lprintf("List empty");
        return;
    }
    for (; head; head = head->next) {
        if (head->type == STR_LIST) {
            str = (char *)head->data;
        }
    }
    if (!str)
        lprintf("NULL");
    else
        lprintf("%s", str);
}
