/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** animate_menu
*/

#include <my_runner/runner.h>
#include <my_runner/scene.h>

void animate_menu(scene_t *scene,  game_manager_t *manager)
{
    CLEAR_WINDOW(manager->window);
    DRAW_SPRITE(manager->window, scene->menu.sprite_bg);
    DRAW_SPRITE(manager->window, scene->menu.sprite_logo);
    draw_menu_cursor(scene, manager);
    DRAW_SPRITE(manager->window, scene->menu.sprite_b1);
    DRAW_SPRITE(manager->window, scene->menu.sprite_b2);
    DISPLAY_WINDOW(manager->window);
}

