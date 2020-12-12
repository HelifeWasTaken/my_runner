/*
** EPITECH PROJECT, 2020
** lputnbr
** File description:
** lodeus_lib
*/

#include <lodeus/fd.h>

size_t lputnbr(long long nb)
{
    return (ldputnbr(STDOUT_FILENO, nb));
}

size_t lputnbr_u(long long nb)
{
    return (ldputnbr_u(STDOUT_FILENO, nb));
}

size_t lputnbr_base(long long nb, unsigned int base, bool uppercase)
{
    return (ldputnbr_base(STDOUT_FILENO, nb, base, uppercase));
}

size_t lputfloat(double nb, unsigned char precision)
{
    return (ldputfloat(STDOUT_FILENO, nb, precision));
}
