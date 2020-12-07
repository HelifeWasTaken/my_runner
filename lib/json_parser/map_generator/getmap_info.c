/*
** EPITECH PROJECT, 2020
** getmap_info.c
** File description:
** lodeus_lib
*/

#include <lodeus/json_parser/mapgen.h>

static map_t getmap_array(mapgen_t mapinfo)
{
    char *buffer_ptr = mapinfo.buffer;
    map_t map_tab = malloc(sizeof(unsigned int *) * (mapinfo.height + 1));
    mapid_t y;
    mapid_t x;

    for (y = 0; y < mapinfo.height; y++) {
        map_tab[y] = malloc(sizeof(mapid_t) * (mapinfo.width + 1));
        for (x = 0; x <= mapinfo.width; x++) {
            map_tab[y][x] = latoi(buffer_ptr);
            buffer_ptr += lnblen(map_tab[y][x]) + 1;
        }
    }
    return (map_tab);
}

mapgen_t get_map_info(json_t *mapjson)
{
    mapgen_t mapinfo = {0};

    mapinfo.buffer = getoneline(SEEK_STR(mapjson, "mapinfo.filepath"));
    mapinfo.width = getmap_width(mapinfo.buffer);
    mapinfo.height = getmap_height(mapinfo.buffer);
    mapinfo.tile_size.x = SEEK_INT(mapjson, "mapinfo.tile_size.x");
    mapinfo.tile_size.y = SEEK_INT(mapjson, "mapinfo.tile_size.y");
    mapinfo.maparray = getmap_array(mapinfo);
    return (mapinfo);
}
