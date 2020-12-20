/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** scene
*/

#pragma once

#ifndef __RUNNER__SCENE__H__
    #define __RUNNER__SCENE__H__
    #include <my_runner/parallax.h>
    #include <my_runner/player.h>
    #include <my_runner/background.h>
    #include <my_runner/enemy.h>
    #include <my_runner/runner.h>

    typedef struct scene {
        parralax_t *parralax;
        sfTexture **enemy_texture;
        g_background_t *background;
        player_t player;
        frame_t background_frame;
        enemy_t *enemy;
    } scene_t;

    void draw_parralax(scene_t *scene, game_manager_t *manager);
    void draw_background(scene_t *scene, game_manager_t *manager);
    void draw_player(scene_t *scene, game_manager_t *manager);
    void draw_all_game(scene_t *scene, game_manager_t *manager);
    bool init_scene(scene_t *scene, char **av);
    bool map_loader(scene_t *scene, char *filepath);

    void animate_slime(scene_t *scene, game_manager_t *manager, size_t i);
    void animate_mushroom(scene_t *scene, game_manager_t *manager, size_t i);
#endif