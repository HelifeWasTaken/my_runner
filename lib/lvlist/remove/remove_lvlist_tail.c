/*
** EPITECH PROJECT, 2020
** remove_lvlist_tail.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void remove_lvlist_tail(lvlist_t **head)
{
    lvlist_t *head_ptr = *head;

    if (!head_ptr)
        return;
    for (; head_ptr->next; head_ptr = head_ptr->next);
    head_ptr->prev->next = NULL;
    free(head_ptr);
}
