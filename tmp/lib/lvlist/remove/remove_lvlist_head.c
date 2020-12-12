/*
** EPITECH PROJECT, 2020
** remove_lvlist_head.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void remove_lvlist_head(lvlist_t **head)
{
    lvlist_t *tmp = *head;

    *head = (*head)->next;
    free(tmp);
}
