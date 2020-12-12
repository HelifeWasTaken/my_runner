/*
** EPITECH PROJECT, 2020
** freemap.c
** File description:
** lodeus_lib
*/

#include <lodeus/json_parser/mapgen.h>

void free_texture(maptexture_t **texture)
{
    if (*texture) {
        if ((*texture)->next)
            free_texture(&(*texture)->next);
        free((*texture)->name);
        sfTexture_destroy((*texture)->texture);
        free(*texture);
    }
}

void freemap(mapgen_t mapinfo, mapsprite_t *mapsprite, maptexture_t *texture)
{
    free(mapinfo.buffer);
    for (signed long y = 0; y < mapinfo.height; y++)
        free(mapinfo.maparray[y]);
    free(mapinfo.maparray);
    for (signed long i = 0; i < mapinfo.nbasset; i++) {
        free(mapsprite[i].texture_path);
        sfSprite_destroy(mapsprite[i].sprite);
        sfTexture_destroy(mapsprite[i].texture);
    }
    free(mapsprite);
    free_texture(&texture);
}
