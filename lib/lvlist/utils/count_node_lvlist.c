/*
** EPITECH PROJECT, 2020
** count_node_lvlist.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

size_t count_lvlist_node(lvlist_t *head)
{
    size_t i = 0;

    for (; head; head = head->next)
        i++;
    return (i);
}
