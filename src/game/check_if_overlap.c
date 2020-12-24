/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** check_if_overlap
*/

#include <my_runner/scene.h>

bool check_if_overlap(scene_t *scene, size_t i)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(scene->player.sprite);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(scene->enemy[i].sprite);

    return (
            sfFloatRect_contains(&rect, rect2.left, rect2.top) ||
            sfFloatRect_contains(&rect, rect2.left + rect2.width, rect2.top) ||
            sfFloatRect_contains(&rect, rect2.left, rect2.top + rect2.height) ||
            sfFloatRect_contains(&rect, rect2.left + rect2.width,
                rect2.height + rect2.top));
}