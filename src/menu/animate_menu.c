/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** animate_menu
*/

#include <my_runner/runner.h>
#include <my_runner/scene.h>

static void display_string_map_mode(scene_t *scene, game_manager_t *manager)
{
    sfText_setPosition(scene->menu.filepath,
        VECF(WIN_W / 2 - 170, WIN_H - 200));
    if (scene->menu.trigger_error)
        DRAW_SPRITE(manager->window, scene->menu.error_sprite);
    if (manager->map)
        display_info(scene->menu.filepath, manager->window,
            my_strdup("file: "), my_strdup(manager->map));
    else
        display_info(scene->menu.filepath, manager->window,
            my_strdup("file: "), my_strdup(" "));
}

void animate_menu(scene_t *scene,  game_manager_t *manager)
{
    CLEAR_WINDOW(manager->window);
    DRAW_SPRITE(manager->window, scene->menu.sprite_bg);
    DRAW_SPRITE(manager->window, scene->menu.sprite_logo);
    draw_menu_cursor(scene, manager);
    DRAW_SPRITE(manager->window, scene->menu.sprite_b1);
    DRAW_SPRITE(manager->window, scene->menu.sprite_b2);
    if (!manager->infinty_enabled)
        display_string_map_mode(scene, manager);
    else {
        sfText_setPosition(scene->menu.filepath,
            VECF(WIN_W / 2 - 180, WIN_H - 200));
        display_info(scene->menu.filepath, manager->window,
            my_strdup("Infinity mode: "), my_strdup("on"));
    }
    DISPLAY_WINDOW(manager->window);
}
