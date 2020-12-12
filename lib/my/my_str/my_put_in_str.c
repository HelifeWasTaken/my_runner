/*
** EPITECH PROJECT, 2020
** my_put_in_str
** File description:
** put_a_char_in_str
*/

#include <my_stdlib.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>

size_t my_strlen(char const *str);

char *my_put_in_str(char *str, ssize_t const index, char const to_add)
{
    ssize_t size_to_push = my_strlen(str);
    char *pushed = my_calloc(sizeof(char), size_to_push + 2);

    while (size_to_push >= index) {
        pushed[size_to_push + 1] = str[size_to_push];
        size_to_push--;
    }
    pushed[index] = to_add;
    while (size_to_push >= 0) {
        pushed[size_to_push] = str[size_to_push];
        size_to_push--;
    }
    free(str);
    return (pushed);
}
