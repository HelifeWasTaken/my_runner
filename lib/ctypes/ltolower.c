/*
** EPITECH PROJECT, 2020
** ltolower
** File description:
** lodeus_lib
*/

#include <lodeus/ctypes.h>

int ltolower(int c)
{
    return ((lisupper(c) ? c + 32 : c));
}
