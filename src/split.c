/*
** EPITECH PROJECT, 2020
** lstr_to_word_array
** File description:
** lodeus_lib
*/

#include <stdlib.h>
#include <my_str.h>

size_t count_split(char **buffer)
{
    size_t i = 0;

    for (; buffer[i]; i++);
    return (i);
}

void freesplit(char **buffer)
{
    for (int i = 0; buffer[i] != NULL; i++)
        free(buffer[i]);
    free(buffer);
}

static size_t count_separators(char const *str, int separator)
{
    size_t count = 1;

    for (size_t i = 0; str[i]; i++) {
        if (str[i] == separator)
            count++;
    }
    return (count);
}

static char *find_new_str(char const *str,
        int separator, size_t *index_str)
{
    size_t i = *index_str;
    char *new_str;

    while (str[i] && str[i] != separator)
        i++;
    new_str = malloc(sizeof(char) * (i - *index_str + 1));
    new_str = my_strncpy(new_str, str + *index_str, i - *index_str);
    new_str[i - *index_str] = '\0';
    *index_str = ++i;
    return (new_str);
}

char **split(char const *str, int separator)
{
    size_t index_str = 0;
    size_t len_array = count_separators(str, separator);
    char **new_array = malloc(sizeof(char *) * (len_array + 1));

    for (size_t i = 0; i < len_array; i++) {
        new_array[i] = find_new_str(str, separator, &index_str);
    }
    new_array[len_array] = NULL;
    return (new_array);
}
