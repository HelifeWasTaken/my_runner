/*
** EPITECH PROJECT, 2020
** lprint_loop
** File description:
** lodeus_lib
*/

#include <lodeus/ctypes.h>
#include <lodeus/fd.h>

size_t lprint_loop(int c, size_t count)
{
    return (ldprint_loop(STDOUT_FILENO, c, count));
}
