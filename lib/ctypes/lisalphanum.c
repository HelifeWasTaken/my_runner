/*
** EPITECH PROJECT, 2020
** lisalphanum
** File description:
** lodeus_lib
*/

#include <lodeus/ctypes.h>

bool lisalphanum(int c)
{
    return (lisalpha(c) || lisnum(c));
}
