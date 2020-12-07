/*
** EPITECH PROJECT, 2020
** lisprintable
** File description:
** lodeus_lib
*/

#include <lodeus/ctypes.h>

bool lisprintable(int c)
{
    return (!((c >= 0 && c <= 31) || c == 127));
}
