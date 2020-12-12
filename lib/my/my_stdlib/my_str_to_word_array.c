/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** Put words into each array individually
*/

#include <stdlib.h>
#include <my_stdlib.h>
#include <my_str.h>

size_t get_word_len(char const *str, size_t i)
{
    size_t count = 0;

    while (!is_char_alphanum(str[i]) && str[i])
        i++;
    while (is_char_alphanum(str[i]) && str[i]) {
        i++;
        count++;
    }
    return (count);
}

static char *get_word(char const *str, size_t *i, size_t *actual_word_len)
{
    char *temp = malloc(sizeof(char) * (get_word_len(str, *i) + 1));

    *actual_word_len = 0;
    while (!is_char_alphanum(str[*i]) && str[*i])
        (*i)++;
    while (is_char_alphanum(str[*i]) && str[*i]) {
        temp[*actual_word_len] = str[*i];
        (*actual_word_len)++;
        (*i)++;
    }
    return (temp);
}

char **my_str_to_word_array(char const *str)
{
    char **answer = malloc(sizeof(char *) * (my_word_count(str) + 1));
    size_t i = 0;
    size_t actual_word_len = 0;
    char *temp;
    size_t count = 0;

    while (str[i]) {
        if (is_char_alphanum(str[i])) {
            temp = get_word(str, &i, &actual_word_len);
            answer[count] = malloc(sizeof(char) * actual_word_len);
            answer[count] = my_strdup(temp);
            count++;
        }
        else
            i++;
    }
    answer[count] = NULL;
    return (answer);
}
