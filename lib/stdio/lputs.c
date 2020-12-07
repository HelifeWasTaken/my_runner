/*
** EPITECH PROJECT, 2020
** lputs
** File description:
** lodeus_lib
*/

#include <lodeus/fd.h>

size_t lputs(char const *str)
{
    return (ldputs(STDOUT_FILENO, str));
}
