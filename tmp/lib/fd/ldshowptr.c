/*
** EPITECH PROJECT, 2020
** ldshowptr
** File description:
** lodeus_lib
*/

#include <lodeus/fd.h>

size_t ldshow_ptr(int fd, long long nb)
{
    return (ldputnbr_u(fd, nb));
}
