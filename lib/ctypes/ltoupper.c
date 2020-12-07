/*
** EPITECH PROJECT, 2020
** ltoupper
** File description:
** lodeus_lib
*/

#include <lodeus/ctypes.h>

int ltoupper(int c)
{
    return ((lislower(c) ? c - 32 : c));
}
