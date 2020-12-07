/*
** EPITECH PROJECT, 2020
** lnblen_lnbulen
** File description:
** lodeus_lib
*/

#include <lodeus/ctypes.h>

size_t lnblen(long long nb)
{
    size_t size = 1;

    if (nb < 0) {
        nb = -nb;
        size++;
    }
    while (nb >= 10) {
        nb /= 10;
        size++;
    }
    return (size);
}

size_t lnbulen(long long nb)
{
    size_t size = 1;

    while (nb >= 10) {
        nb /= 10;
        size++;
    }
    return (size);
}

size_t lnbbaselen(long long nb, int base)
{
    size_t size = 1;

    while (nb >= base) {
        nb /= base;
        size++;
    }
    return (size);
}
