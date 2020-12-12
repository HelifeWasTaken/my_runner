/*
** EPITECH PROJECT, 2020
** lvlist_auto_cast.c
** File description:
** lodeus_lib
*/

#include <lodeus/lvlist.h>

int64_t cast_lvlist_to_int(void *data)
{
    return ((int64_t)data);
}

uint64_t cast_lvlist_to_uint(void *data)
{
    return ((uint64_t)data);
}

char *cast_lvlist_to_str(void *data)
{
    return ((char *)data);
}
