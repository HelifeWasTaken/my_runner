/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** load_end
*/

#include <my_runner/scene.h>

bool load_end(scene_t *scene)
{
    scene->end.music = CREATE_MUSIC(END_MUSIC_ASSET);
    scene->end.sprite_bg = sfSprite_create();
    scene->end.texture_bg = CREATE_TEXTURE(END_BG_ASSET);
    scene->end.score_board = sfText_create();
    scene->end.top_str = NULL;
    scene->end.username = NULL;
    scene->end.username_text = sfText_create();
    if (!scene->end.music || !scene->end.texture_bg)
        return (false);
    SET_TEXTURE(scene->end.sprite_bg, scene->end.texture_bg);
    sfText_setFont(scene->end.score_board, scene->text.font_score);
    sfText_setFont(scene->end.username_text, scene->menu.font_file);
    return (true);
}