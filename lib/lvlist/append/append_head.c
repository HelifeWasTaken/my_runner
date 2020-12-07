/*
** EPITECH PROJECT, 2020
** append_head.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void lvlist_append_to_head(lvlist_t **head, void *data, uint32_t type)
{
    lvlist_t *new_node = add_lvlist_node(data, type);

    new_node->next = *head;
    if (*head)
        (*head)->prev = new_node;
    *head = new_node;
}
