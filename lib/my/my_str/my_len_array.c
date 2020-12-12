/*
** EPITECH PROJECT, 2020
** my_get_len_array.c
** File description:
** Get how many characters in total there is in my array
*/

#include <stddef.h>

size_t my_strlen(char const *dest);

size_t my_len_array(size_t const nb_elements, char **array)
{
    size_t size = 0;

    for (size_t i = 0; i < nb_elements; i++)
        size += my_strlen(array[i]);
    return (size);
}
