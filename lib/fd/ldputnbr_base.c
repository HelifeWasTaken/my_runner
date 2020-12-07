/*
** EPITECH PROJECT, 2020
** ldputnbr_base
** File description:
** lodeus_lib
*/

#include <lodeus/fd.h>

static size_t process_base(int fd, unsigned long long nb,
        char const *base, unsigned int basesize)
{
        return ((nb >= basesize) ?
            process_base(fd, nb / basesize, base, basesize) +
            ldputchar(fd, base[nb % basesize]) :
            ldputchar(fd, base[nb]));
}

size_t ldputnbr_base(int fd, unsigned long long nb, unsigned int base,
        bool uppercase)
{
    return ((uppercase) ?
            process_base(fd, nb, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", base) :
            process_base(fd, nb, "0123456789abcdefghjiklmnopqrstuvwxyz", base));
}
