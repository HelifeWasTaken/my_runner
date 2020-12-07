/*
** EPITECH PROJECT, 2020
** latoll
** File description:
** lodeus_lib
*/

#include <lodeus/ctypes.h>
#include <lodeus/assert.h>
#include <stdio.h>

static char get_sign(char c, size_t *i)
{
    if (c == '-') {
        (*i)++;
        return (-1);
    }
    return (1);
}

int latoll(char const *str)
{
    size_t i = 0;
    char sign = get_sign(str[0], &i);
    long long result = 0;

    while (lisnum(str[i])) {
        if (DOES_ADD_OVERFLOW(result, str[i] - '0'))
            return (0);
        else
            result += str[i] - '0';
        if (lisnum(str[i + 1])) {
            if (DOES_MUL_OVERFLOW(result, 10))
                return (0);
            else
                result *= 10;
        }
        i++;
    }
    return (result * sign);
}
