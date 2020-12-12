/*
** EPITECH PROJECT, 2020
** draw_all_game.c
** File description:
** draw_game
*/

#include <my_runner.h>

void draw_all_game(scene_t *scene, game_manager_t *manager)
{
    CLEAR_WINDOW(manager->window);
    draw_background(scene, manager);
    draw_parralax(scene, manager);
    draw_player(scene, manager);
    DISPLAY_WINDOW(manager->window);
}