/*
** EPITECH PROJECT, 2020
** lbzero
** File description:
** lodeus_lib
*/

#include <lodeus/ctypes.h>
#include <lodeus/string.h>

void lbzero(void *data, size_t size)
{
    lmemset(data, 0, size);
}
