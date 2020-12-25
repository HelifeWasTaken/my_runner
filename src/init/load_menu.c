/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** load_menu
*/

#include <my_runner/scene.h>

static void set_menu(scene_t *scene)
{
    SET_TEXTURE(scene->menu.sprite_bg, scene->menu.texture_bg);
    SET_TEXTURE(scene->menu.sprite_logo, scene->menu.texture_logo);
    SET_TEXTURE(scene->menu.sprite_b1, scene->menu.texture_b1);
    SET_TEXTURE(scene->menu.sprite_b2, scene->menu.texture_b2);
    SET_TEXTURE(scene->menu.error_sprite, scene->menu.error_texture);
    sfSprite_setScale(scene->menu.sprite_bg, VECF(1.3, 1.3));
    sfSprite_setPosition(scene->menu.sprite_logo, VECF(WIN_W / 2 - 240, 175));
    sfSprite_setPosition(scene->menu.sprite_b1, VECF(WIN_W - 775, WIN_H - 400));
    sfSprite_setPosition(scene->menu.sprite_b2, VECF(WIN_W - 760, WIN_H - 300));
    sfSprite_setPosition(scene->menu.error_sprite,
        VECF(WIN_W - 530, WIN_H - 383));
    sfSprite_setScale(scene->menu.error_sprite, VECF(0.5, 0.5));
    sfText_setFont(scene->menu.filepath, scene->menu.font_file);
}

bool load_menu(scene_t *scene)
{
    scene->menu.sprite_bg = sfSprite_create();
    scene->menu.sprite_logo = sfSprite_create();
    scene->menu.sprite_b1 = sfSprite_create();
    scene->menu.sprite_b2 = sfSprite_create();
    scene->menu.error_sprite = sfSprite_create();
    scene->menu.filepath = sfText_create();
    scene->menu.texture_bg = CREATE_TEXTURE(BACKGROUND_MENU_ASSET);
    scene->menu.texture_logo = CREATE_TEXTURE(LOGO_MENU_ASSET);
    scene->menu.texture_b1 = CREATE_TEXTURE(PLAY_BUTTON_ASSET);
    scene->menu.texture_b2 = CREATE_TEXTURE(QUIT_BUTTON_ASSET);
    scene->menu.music = CREATE_MUSIC(SOUND_MENU_ASSET);
    scene->menu.error_texture = CREATE_TEXTURE(ERROR_BUTTON_ASSET);
    scene->menu.font_file = sfFont_createFromFile(FONT_ASSET);
    if (!scene->menu.texture_bg || !scene->menu.music ||
            !scene->menu.texture_b1 || !scene->menu.texture_b2 ||
            !scene->menu.error_texture || !scene->menu.font_file)
        return (false);
    set_menu(scene);
    return (true);
}