/*
** EPITECH PROJECT, 2020
** reverse_lvlist.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void reverse_lvlist(lvlist_t **head)
{
    lvlist_t *tmp = NULL;
    lvlist_t *current = *head;

    while (current) {
        tmp = current->prev;
        current->prev = current->next;
        current->next = tmp;
        current = current->prev;
    }
    if (tmp)
        *head = tmp->prev;
}
