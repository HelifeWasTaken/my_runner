/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** load_text_textures
*/

#include <my_runner/scene.h>

bool load_text_textures(scene_t *scene)
{
    scene->text.font_score = sfFont_createFromFile(FONT_SCORE_ASSET);
    if (scene->text.font_score == NULL)
        return (false);
    scene->text.text_score = sfText_create();
    sfText_setFont(scene->text.text_score, scene->text.font_score);
    sfText_setPosition(scene->text.text_score, VECF(25, 25));
    return (true);
}