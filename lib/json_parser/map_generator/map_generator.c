/*
** EPITECH PROJECT, 2020
** map_generator.c
** File description:
** lodeus_lib
*/

#include <lodeus/json_parser/mapgen.h>

lmap_t mapgenerator(char *filepath)
{
    json_t *mapjson = jsonparser(filepath);
    mapgen_t mapinfo = get_map_info(mapjson);
    maptexture_t *maptexture = get_textures(mapjson);
    mapsprite_t *mapsprite = getmap_sprites(mapjson, mapinfo, maptexture);

    return ((lmap_t){mapinfo, mapsprite, maptexture});
}
