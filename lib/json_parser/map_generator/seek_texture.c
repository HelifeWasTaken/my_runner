/*
** EPITECH PROJECT, 2020
** seek_texture.c
** File description:
** lodeus_lib
*/

#include <lodeus/json_parser/mapgen.h>

sfTexture *seek_texture(maptexture_t *texturemap, char *filename)
{
    for (; texturemap; texturemap = texturemap->next) {
        if (lstrcmp(filename, texturemap->name) == 0)
            return (texturemap->texture);
    }
    return (NULL);
}
