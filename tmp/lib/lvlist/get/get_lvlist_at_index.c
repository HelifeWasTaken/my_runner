/*
** EPITECH PROJECT, 2020
** get_lvlist_at_index.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void *get_lvlist_at_index(lvlist_t **head, size_t i, bool popit)
{
    size_t j = 0;
    lvlist_t *head_ptr = *head;
    void *stock = NULL;

    for (; head_ptr && j < i; head_ptr = head_ptr->next, j++);
    if (!head_ptr)
        return (NULL);
    stock = head_ptr->data;
    if (popit)
        remove_lvlist_at_index(head, j);
    return (stock);
}
