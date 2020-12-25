/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** bubble_sort_score_board
*/

#include <my_runner/scene.h>
#include <my_runner/score.h>

void swap_info(unsigned long long *a, unsigned long long *b, void **c, void **d)
{
    int z = *a;
    void *w = *c;

    *a = *b;
    *b = z;
    *c = *d;
    *d = w;
}

void process_swap_bubble(score_t *ptr, bool *swapped)
{
    if (ptr->score > ptr->next->score) {
        swap_info(&ptr->score,
                &ptr->next->score,
                (void **)&ptr->username,
                (void **)&ptr->next->username);
        *swapped = true;
    }
}

void bubble_sort_score_board(score_t **head)
{
    score_t *ptr = *head;
    bool swapped = false;

    do {
        ptr = *head;
        swapped = false;
        for (; ptr->next; ptr = ptr->next)
            process_swap_bubble(ptr, &swapped);
    } while (swapped);
}
