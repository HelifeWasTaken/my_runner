/*
** EPITECH PROJECT, 2020
** lputchar
** File description:
** lodeus_lib
*/

#include <lodeus/fd.h>

size_t lputchar(char const c)
{
    return (ldputchar(STDOUT_FILENO, c));
}
