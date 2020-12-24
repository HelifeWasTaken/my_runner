/*
** EPITECH PROJECT, 2020
** init_scene.c
** File description:
** scene
*/

#include <my_runner/scene.h>

bool load_menu(scene_t *scene)
{
    scene->menu.sprite_bg = sfSprite_create();
    scene->menu.sprite_logo = sfSprite_create();
    scene->menu.sprite_b1 = sfSprite_create();
    scene->menu.sprite_b2 = sfSprite_create();
    scene->menu.texture_bg = CREATE_TEXTURE(BACKGROUND_MENU_ASSET);
    scene->menu.texture_logo = CREATE_TEXTURE(LOGO_MENU_ASSET);
    scene->menu.texture_b1 = CREATE_TEXTURE(PLAY_BUTTON_ASSET);
    scene->menu.texture_b2 = CREATE_TEXTURE(QUIT_BUTTON_ASSET);
    scene->menu.music = CREATE_MUSIC(SOUND_MENU_ASSET);
    if (!scene->menu.texture_bg || !scene->menu.music ||
        !scene->menu.texture_b1 || !scene->menu.texture_b2)
        return (false);
    SET_TEXTURE(scene->menu.sprite_bg, scene->menu.texture_bg);
    SET_TEXTURE(scene->menu.sprite_logo, scene->menu.texture_logo);
    SET_TEXTURE(scene->menu.sprite_b1, scene->menu.texture_b1);
    SET_TEXTURE(scene->menu.sprite_b2, scene->menu.texture_b2);
    sfSprite_setScale(scene->menu.sprite_bg, VECF(1.3, 1.3));
    sfSprite_setPosition(scene->menu.sprite_logo, VECF(WIN_W / 2 - 240, 175));
    sfSprite_setPosition(scene->menu.sprite_b1, VECF(WIN_W - 775, WIN_H - 400));
    sfSprite_setPosition(scene->menu.sprite_b2, VECF(WIN_W - 760, WIN_H - 300));
    return (true);
}

bool init_scene(scene_t *scene)
{
    scene->enemy = NULL;
    return (
            get_parralax_texture(scene) &&
            get_background(scene) &&
            get_player(scene) &&
            load_enemy_textures(scene) &&
            load_text_textures(scene) &&
            load_music(scene) &&
            load_menu(scene)
           );
}
