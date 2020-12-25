/*
** EPITECH PROJECT, 2020
** init_scene.c
** File description:
** scene
*/

#include <my_runner/scene.h>

bool init_scene(scene_t *scene)
{
    scene->enemy = NULL;
    scene->world.choice = -1;
    return (
            get_parralax_texture(scene) &&
            get_background(scene) &&
            get_player(scene) &&
            load_enemy_textures(scene) &&
            load_text_textures(scene) &&
            load_music(scene) &&
            load_menu(scene) &&
            load_end(scene));
}
