/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** destroy_menu
*/

#include <my_runner/free.h>

void destroy_menu(scene_t *scene)
{
    if (scene->menu.music)
        sfMusic_destroy(scene->menu.music);
    if (scene->menu.sprite_bg)
        sfSprite_destroy(scene->menu.sprite_bg);
    if (scene->menu.texture_bg)
        sfTexture_destroy(scene->menu.texture_bg);
    if (scene->menu.sprite_logo)
        sfSprite_destroy(scene->menu.sprite_logo);
    if (scene->menu.texture_logo)
        sfTexture_destroy(scene->menu.texture_logo);
    if (scene->menu.sprite_b1)
        sfSprite_destroy(scene->menu.sprite_b1);
    if (scene->menu.texture_b1)
        sfTexture_destroy(scene->menu.texture_b1);
    if (scene->menu.sprite_b2)
        sfSprite_destroy(scene->menu.sprite_b2);
    if (scene->menu.texture_b2)
        sfTexture_destroy(scene->menu.texture_b2);
}
