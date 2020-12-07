/*
** EPITECH PROJECT, 2020
** display_lvlist_type.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

void display_lvlist_type(uint32_t type_value)
{
    char type[3][5] = {"int", "uint", "str"};

    lprintf("%s", type[type_value]);
}
