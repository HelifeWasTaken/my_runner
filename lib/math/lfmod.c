/*
** EPITECH PROJECT, 2020
** modfloat
** File description:
** lodeus_lib
*/

#include <lodeus/ctypes.h>

char lfmod(double nb, unsigned char mod)
{
    double value;

    value = (nb < 0) ? -nb : nb;
    while (value >= mod)
        value -= mod;
    return ((nb < 0) ? (char)-value : (char)value);
}
