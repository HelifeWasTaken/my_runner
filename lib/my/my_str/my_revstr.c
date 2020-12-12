/*
** EPITECH PROJECT, 2020
** my_evil_str
** File description:
** putstr str
*/

#include <stddef.h>

size_t my_strlen(char const *str);

char *my_revstr(char *str)
{
    size_t len = my_strlen(str) - 1;
    char temp = 0;

    if (len <= 0)
        return (str);
    for (size_t i = 0; i < my_strlen(str) / 2; i++) {
        temp = str[len - i];
        str[len - i] = str[i];
        str[i] = temp;
    }
    return (str);
}
