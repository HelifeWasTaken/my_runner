/*
** EPITECH PROJECT, 2020
** get_lvlist_next_str.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

char *get_lvlist_next_str_occurence(lvlist_t **head, bool popit)
{
    lvlist_t *head_ptr = *head;
    char *stock = NULL;
    size_t i = 0;

    if (!head_ptr)
        return (NULL);
    for (; head_ptr && head_ptr->type != STR_LIST; head_ptr = head_ptr->next)
        i++;
    if (!head_ptr)
        return (NULL);
    stock = (char *)head_ptr->data;
    if (popit)
        remove_lvlist_at_index(head, i);
    return (stock);
}
