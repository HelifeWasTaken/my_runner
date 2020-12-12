/*
** EPITECH PROJECT, 2020
** create_lvlist_node.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

lvlist_t *add_lvlist_node(void *data, uint32_t type)
{
    lvlist_t *new_node = malloc(sizeof(lvlist_t));

    new_node->data = data;
    new_node->type = type;
    new_node->next = NULL;
    new_node->prev = NULL;
    return (new_node);
}

