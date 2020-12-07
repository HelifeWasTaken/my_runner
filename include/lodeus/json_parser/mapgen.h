/*
** EPITECH PROJECT, 2020
** mapgen.h
** File description:
** lodeus_lib
*/

#ifndef __LODEUS__MAP_GEN__H__
#define __LODEUS__MAP_GEN__H__
#include <lodeus/ctypes.h>
#include <lodeus/json_parser/json.h>
#include <SFML/Graphics.h>
#include <lodeus/stdlib.h>

typedef signed long ** map_t;
typedef signed long mapid_t;

typedef struct mapgen {
    char *buffer;
    signed long width;
    signed long height;
    sfVector2i tile_size;
    signed long nbasset;
    map_t maparray;
} mapgen_t;

typedef struct mapsprite {
    char *texture_path;
    signed long sizex;
    signed long sizey;
    signed long posx;
    signed long posy;
    sfTexture *texture;
    sfSprite *sprite;
} mapsprite_t;

typedef struct maptexture {
    char *name;
    sfTexture *texture;
    struct maptexture *next;
} maptexture_t;

typedef struct lodemap {
    mapgen_t map;
    mapsprite_t *sprites;
    maptexture_t *texture;
} lmap_t;

lmap_t mapgenerator(char *filepath);
size_t getmap_height(char *buffer);
size_t getmap_width(char *buffer);
void display_map(mapgen_t mapinfo, mapsprite_t *maptexture,
    sfRenderWindow *window);
mapsprite_t *getmap_sprites(json_t *mapjson, mapgen_t mapinfo,
    maptexture_t *maptexture);
mapgen_t get_map_info(json_t *mapjson);
sfTexture *seek_texture(maptexture_t *texturemap, char *filename);
maptexture_t *create_texture_node(json_t *conf);
void freemap(mapgen_t mapinfo, mapsprite_t *mapsprite, maptexture_t *texture);
void free_texture(maptexture_t **texture);
void get_texture_node(json_t *conf, maptexture_t **texture);
maptexture_t *get_textures(json_t *conf);
#define FREE_MAP(lmap) freemap(lmap.map, lmap.sprites, lmap.texture)
#define DISP_MAP(lmap, window) \
    display_map(lmap.map, lmap.sprites, window)
#endif
