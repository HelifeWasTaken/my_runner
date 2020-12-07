/*
** EPITECH PROJECT, 2020
** get_lvlist_next_uint.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

uint64_t get_lvlist_next_uint_occurence(lvlist_t **head, bool popit)
{
    lvlist_t *head_ptr = *head;
    uint64_t stock = 0;
    size_t i = 0;

    if (!head_ptr)
        return (0);
    for (; head_ptr && head_ptr->type != UINT_LIST; head_ptr = head_ptr->next)
        i++;
    if (!head_ptr)
        return (0);
    stock = (uint64_t)head_ptr->data;
    if (popit)
        remove_lvlist_at_index(head, i);
    return (stock);
}
