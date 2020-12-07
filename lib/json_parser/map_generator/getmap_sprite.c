/*
** EPITECH PROJECT, 2020
** getmap_sprite.c
** File description:
** lodeus_lib
*/

#include <lodeus/json_parser/mapgen.h>

static mapsprite_t fillsprite(json_t *confptr, mapgen_t mapinfo,
    maptexture_t *maptexture)
{
    mapsprite_t mt;

    mt.sprite = sfSprite_create();
    mt.texture_path = lstrdup(SEEK_STR(confptr, "file"));
    mt.posx = SEEK_INT(confptr, "position.x");
    mt.posy = SEEK_INT(confptr, "position.y");
    sfSprite_setScale(mt.sprite,
            (sfVector2f){
            SEEK_INT(confptr, "scale.x"), SEEK_INT(confptr, "scale.y")});
    sfSprite_setTexture(mt.sprite,
        seek_texture(maptexture, mt.texture_path), sfFalse);
    sfSprite_setTextureRect(mt.sprite,
            (sfIntRect){mt.posx, mt.posy,
            mapinfo.tile_size.x, mapinfo.tile_size.y});
    return (mt);
}

mapsprite_t *getmap_sprites(json_t *mapjson, mapgen_t mapinfo,
    maptexture_t *maptexture)
{
    size_t i = 0;
    mapsprite_t *mt = NULL;

    mapinfo.nbasset = SEEK_INT(mapjson, "mapinfo.nbasset");
    mapjson = gotoinfo(mapjson, "sprites.1");
    mt = malloc(sizeof(mapsprite_t) * mapinfo.nbasset);
    for (json_t *confptr = NULL; mapjson; mapjson = mapjson->next, i++) {
        confptr = mapjson->datain;
        mt[i] = fillsprite(confptr, mapinfo, maptexture);
    }
    return (mt);
}
