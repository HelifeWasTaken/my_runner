/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** destroy_enemy_array
*/

#include <my_runner/free.h>

void destroy_enemy_array(scene_t *scene)
{
    size_t i = 0;

    if (!scene->enemy)
        return;
    for (; scene->enemy[i].enemy_id != -2; i++) {
        if (scene->enemy[i].sprite)
            sfSprite_destroy(scene->enemy[i].sprite);
    }
    if (scene->enemy[i].sprite)
        sfSprite_destroy(scene->enemy[i].sprite);
    free(scene->enemy);
}