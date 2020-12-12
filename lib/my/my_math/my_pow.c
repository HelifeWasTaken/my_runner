/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** compute power iterative
*/

long long my_pow(long long nb, int power)
{
    long long nb_copy = nb;

    if (power <= 0)
        return (power == 0);
    if (power > 1)
        nb = nb * my_pow(nb_copy, power - 1);
    return (nb);
}