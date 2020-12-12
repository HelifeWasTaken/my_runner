/*
** EPITECH PROJECT, 2020
** create_texture_node.c
** File description:
** lodeus_lib
*/

#include <lodeus/json_parser/mapgen.h>

maptexture_t *create_texture_node(json_t *conf)
{
    maptexture_t *new_node = malloc(sizeof(maptexture_t));

    new_node->name = lstrdup((jsonstr_t)conf->key);
    new_node->texture =
        sfTexture_createFromFile((jsonstr_t)conf->key_value, NULL);
    new_node->next = NULL;
    return (new_node);
}
