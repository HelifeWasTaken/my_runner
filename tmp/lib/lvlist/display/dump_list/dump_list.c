/*
** EPITECH PROJECT, 2020
** dump_list.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void dump_lvlist(lvlist_t *head)
{
    size_t i = 0;
    void (*disp_func[3])(lvlist_t *head, size_t i) =
    {&dump_display_int, &dump_display_uint, &dump_display_str};

    for (; head; head = head->next) {
        (*disp_func[head->type])(head, i);
        i++;
    }
    lprintf("List n°%lu : EOL\n", i);
}

void dump_lvlist_reverse(lvlist_t *head)
{
    size_t i = 0;
    void (*disp_func[3])(lvlist_t *head, size_t i) =
    {&dump_display_int, &dump_display_uint, &dump_display_str};

    for (; head->next; head = head->next)
        i++;
    (*disp_func[head->type])(head, i);
    while (i--) {
        head = head->prev;
        (*disp_func[head->type])(head, i);
    }
    lprintf("List n°-1 : EOL\n");
}
