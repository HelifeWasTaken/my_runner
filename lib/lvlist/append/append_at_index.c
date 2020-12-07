/*
** EPITECH PROJECT, 2020
** append_at_index.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

static void real_append_to_index(lvlist_t *mv_ptr, void *data, uint32_t type)
{
    lvlist_t *new_node = add_lvlist_node(data, type);
    lvlist_t *next = mv_ptr->next;

    new_node->next = next;
    mv_ptr->next = new_node;
}

void lvlist_append_to_index(lvlist_t **head, void *data,
        uint32_t type, size_t index)
{
    size_t i;
    lvlist_t *mv_ptr = *head;

    if (!index) {
        lvlist_append_to_head(head, data, type);
        return;
    }
    for (i = 0; mv_ptr->next && i < index - 1; i++)
        mv_ptr = mv_ptr->next;
    if (!mv_ptr->next) {
        lprintf("Reached end before index - TAIL - NULL - %ld\n", i);
        return;
    }
    real_append_to_index(mv_ptr, data, type);
}
