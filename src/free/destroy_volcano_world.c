/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** destroy_volcano_world
*/

#include <my_runner/scene.h>

static void destroy_volcano_world_parralax(scene_t *scene)
{
    if (scene->world.volcano.para == NULL)
        return;
    for (size_t i = 0; i < NB_PARA_VOLCANO; i++) {
        if (scene->world.volcano.para[i].layer)
            sfSprite_destroy(scene->world.volcano.para[i].layer);
        if (scene->world.volcano.para[i].texture)
            sfTexture_destroy(scene->world.volcano.para[i].texture);
    }
    free(scene->world.volcano.para);
}

static void destroy_volcano_world_background(scene_t *scene)
{
    if (scene->world.volcano.bg == NULL)
        return;
    for (size_t i = 0; i < NB_BG_VOLCANO; i++) {
        if (scene->world.volcano.bg[i].layer)
            sfSprite_destroy(scene->world.volcano.bg[i].layer);
        if (scene->world.volcano.bg[i].texture)
            sfTexture_destroy(scene->world.volcano.bg[i].texture);
    }
    free(scene->world.volcano.bg);
}

void destroy_volcano_world(scene_t *scene)
{
    destroy_volcano_world_background(scene);
    destroy_volcano_world_parralax(scene);
}

