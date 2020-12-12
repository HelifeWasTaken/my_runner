/*
** EPITECH PROJECT, 2020
** lsqrt
** File description:
** lodeus_lib
*/

unsigned long long lsqrt(unsigned long long x)
{
    unsigned long long tmp = 0;

    while (tmp <= x / 2) {
        if (tmp * tmp == x)
            return (tmp);
        tmp++;
    }
    return (x / 2);
}
