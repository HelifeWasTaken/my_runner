/*
** EPITECH PROJECT, 2020
** remove_lvlist_at_index.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void remove_lvlist_at_index(lvlist_t **head, size_t index)
{
    lvlist_t *head_ptr = *head;

    for (size_t i = 0; i < index && head_ptr; head_ptr = head_ptr->next, i++);
    if (!head_ptr)
        return;
    if (!head_ptr->prev) {
        remove_lvlist_head(head);
        return;
    }
    if (!head_ptr->next) {
        head_ptr->prev->next = NULL;
        free(head_ptr);
        return;
    }
    head_ptr->prev->next = head_ptr->next;
    head_ptr->next->prev = head_ptr->prev;
    free(head_ptr);
}
