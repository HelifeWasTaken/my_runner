/*
** EPITECH PROJECT, 2020
** clear_lvlist.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>
#include <unistd.h>

void clear_lvlist(lvlist_t **head)
{
    lvlist_t *head_ptr = *head;
    lvlist_t *next = NULL;

    if (!head_ptr)
        return;
    next = head_ptr->next;
    while (next) {
        free(head_ptr);
        head_ptr = next;
        next = next->next;
    }
    free(head_ptr);
    *head = NULL;
}
