/*
** EPITECH PROJECT, 2020
** my_sort_int_array
** File description:
** sort_an_array
*/

#include <stddef.h>

void my_swap(int *a, int *b);

static void swap_the_array(int *array, size_t size)
{
    for (size_t i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1])
            my_swap(&array[i], &array[i + 1]);
    }
}

void my_sort_int_array(int *array, size_t size)
{
    for (size_t i = 0; i < size; i++)
        swap_the_array(array, size);
}
