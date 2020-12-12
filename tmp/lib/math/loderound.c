/*
** EPITECH PROJECT, 2020
** lround
** File description:
** lodeus_lib
*/

#include <lodeus/ctypes.h>
#include <lodeus/assert.h>
#include <lodeus/math.h>
#include <lodeus/stdio.h>

double loderound(double nb, unsigned char precision)
{
    double rounded_to_int = (long long)nb;

    nb = nb - rounded_to_int;
    for (char i = 0; i < precision; i++)
        nb *= 10.0f;
    nb = ((long long)nb % 10 >= 5) ?
        nb + 10 - (long long)nb % 10 : nb - (long long)nb % 10;
    for (char i = 0; i < precision; i++)
        nb *= 0.1f;
    return (nb + rounded_to_int);
}
