/*
** EPITECH PROJECT, 2020
** lswap
** File description:
** lodeus_lib
*/

void lswap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
