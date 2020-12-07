/*
** EPITECH PROJECT, 2020
** lputfloat
** File description:
** lodeus_lib
*/

#include <lodeus/fd.h>

static size_t print_precision(int fd, long long nb,
    unsigned char precision)
{
    if (precision) {
        return ((nb) ?
            print_precision(fd, nb / 10, --precision) +
            ldputchar(fd, nb % 10 + '0') :
            print_precision(fd, nb, --precision) + ldputchar(fd, '0'));
    }
    return (0);
}

static long long get_precision_in_float(double nb, unsigned char precision)
{
    double rounded_to_int = (long long)nb;

    nb = nb - rounded_to_int;
    for (char i = 0; i < precision; i++)
        nb *= 10.0f;
    return ((long long)nb);
}

size_t ldputfloat(int fd, double nb, unsigned char precision)
{
    precision = (!precision) ? 1 : precision;
    return (ldputnbr(fd, (long long)nb) + ldputchar(fd, '.') +
        print_precision(fd, get_precision_in_float(nb, precision), precision));
}
