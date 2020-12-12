/*
** EPITECH PROJECT, 2020
** get_textures.c
** File description:
** lodeus_lib
*/

#include <lodeus/json_parser/mapgen.h>

maptexture_t *get_textures(json_t *conf)
{
    maptexture_t *texture = NULL;

    conf = gotoinfo(conf, "textures");
    conf = conf->datain;
    for (; conf; conf = conf->next)
        get_texture_node(conf, &texture);
    return (texture);
}
