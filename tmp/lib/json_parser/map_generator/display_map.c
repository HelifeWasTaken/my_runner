/*
** EPITECH PROJECT, 2020
** display_map.c
** File description:
** lodeus_lib
*/

#include <lodeus/json_parser/mapgen.h>

void display_map(mapgen_t mapinfo, mapsprite_t *mapsprite,
        sfRenderWindow *window)
{
    mapid_t id;

    for (signed long y = 0; y < mapinfo.height; y++) {
        for (signed long x = 0; x < mapinfo.width; x++) {
            id = mapinfo.maparray[y][x];
            if (id == -1)
                continue;
            sfSprite_setPosition(mapsprite[(signed long)id].sprite,
                    (sfVector2f){(double)mapinfo.tile_size.x * (x),
                    (double)mapinfo.tile_size.y * y});
            sfRenderWindow_drawSprite(window, mapsprite[id].sprite, NULL);
        }
    }
}
