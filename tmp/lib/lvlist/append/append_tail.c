/*
** EPITECH PROJECT, 2020
** append_tail.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void lvlist_append_to_tail(lvlist_t **head, void *data, uint32_t type)
{
    lvlist_t *mv_ptr = *head;

    if (*head == NULL) {
        lvlist_append_to_head(head, data, type);
        return;
    }
    for (; mv_ptr->next != NULL; mv_ptr = mv_ptr->next);
    mv_ptr->next = add_lvlist_node(data, type);
    mv_ptr->next->prev = mv_ptr;
}
