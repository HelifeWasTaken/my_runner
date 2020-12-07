/*
** EPITECH PROJECT, 2020
** lrevstr
** File description:
** lodeus_lib
*/

#include <lodeus/ctypes.h>
#include <lodeus/string.h>

char *lrevstr(char *str)
{
    size_t len_str = lstrlen(str) - 1;
    char temp;

    for (size_t i = 0; i <= len_str / 2; i++) {
        temp = str[i];
        str[i] = str[len_str - i];
        str[len_str - i] = temp;
    }
    return (str);
}
