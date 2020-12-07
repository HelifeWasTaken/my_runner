/*
** EPITECH PROJECT, 2020
** get_lvlist_next_int.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

int64_t get_lvlist_next_int_occurence(lvlist_t **head, bool popit)
{
    lvlist_t *head_ptr = *head;
    int64_t stock = 0;
    size_t i = 0;

    if (!head_ptr)
        return (0);
    for (; head_ptr && head_ptr->type != INT_LIST; head_ptr = head_ptr->next)
        i++;
    if (!head_ptr)
        return (0);
    stock = (int64_t)head_ptr->data;
    if (popit)
        remove_lvlist_at_index(head, i);
    return (stock);
}
