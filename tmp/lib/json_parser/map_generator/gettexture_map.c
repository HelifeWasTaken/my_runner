/*
** EPITECH PROJECT, 2020
** gettexture_map.c
** File description:
** lodeus_lib
*/

#include <lodeus/json_parser/mapgen.h>

void get_texture_node(json_t *conf, maptexture_t **texture)
{
    maptexture_t *ptr = *texture;

    if (!(*texture)) {
        *texture = create_texture_node(conf);
        return;
    }
    for (; ptr->next; ptr = ptr->next);
    ptr->next = create_texture_node(conf);
}
