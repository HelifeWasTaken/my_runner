/*
** EPITECH PROJECT, 2020
** lptr_swap
** File description:
** lodeus_lib
*/

void lptr_swap(void **data1, void **data2)
{
    void *data_tmp = *data1;

    *data1 = *data2;
    *data2 = data_tmp;
}
