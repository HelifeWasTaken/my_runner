/*
** EPITECH PROJECT, 2020
** lpow
** File description:
** lodeus_lib
*/

#include <lodeus/ctypes.h>

static unsigned long long lpow_process(unsigned long long x, int powsize)
{
    unsigned long long orignal_x = x;

    while (--powsize)
        x *= orignal_x;
    return (x);
}

unsigned long long lpow(unsigned long long x, int powsize)
{
    if (powsize < 0)
        return (0);
    if (!powsize)
        return (1);
    if (powsize == 1)
        return (x);
    return (lpow_process(x, powsize));
}
