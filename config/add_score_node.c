/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** add_score_node
*/

#include <my_runner/scene.h>
#include <my_runner/score.h>

static unsigned long long get_long_long(char *array)
{
    unsigned long long res = 0;

    for (size_t i = 0; array[i] && array[i] >= '0' && array[i] <= '9'; i++) {
        res += array[i] - '0';
        if (array[i + 1] && array[i + 1] >= '0' && array[i + 1] <= '9')
            res *= 10;
    }
    return (res);
}

static score_t *add_node(char **array)
{
    score_t *ptr = malloc(sizeof(score_t));

    ptr->username = my_strdup(array[0]);
    ptr->score = get_long_long(array[1]);
    ptr->next = NULL;
    return (ptr);
}

bool add_score_node(score_t **head, char *buffer)
{
    score_t *ptr = *head;
    char **array = split(buffer, ':');

    if (array[0] == NULL || array[1] == NULL) {
        freesplit(array);
        return (false);
    }
    if (*head == NULL) {
        *head = add_node(array);
        return (true);
    }
    for (; ptr->next; ptr = ptr->next);
    ptr->next = add_node(array);
    freesplit(array);
    return (true);
}