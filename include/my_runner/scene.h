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
    #include <my_runner/music.h>
    #include <my_runner/font.h>
    #include <my_runner/menu.h>

    typedef struct scene {
        menu_t menu;
        parralax_t *parralax;
        music_t music;
        sfTexture **enemy_texture;
        g_background_t *background;
        player_t player;
        frame_t background_frame;
        enemy_t *enemy;
        text_t text;
    } scene_t;

    /////////////////////////////// DRAW ///////////////////////////////////

    void draw_parralax(scene_t *scene, game_manager_t *manager);
    void draw_background(scene_t *scene, game_manager_t *manager);
    void draw_player(scene_t *scene, game_manager_t *manager);
    void draw_all_game(scene_t *scene, game_manager_t *manager);
    bool get_background(scene_t *scene);
    void animate_slime(scene_t *scene, game_manager_t *manager, size_t i);
    bool get_parralax_texture(scene_t *scene);
    bool load_enemy_textures(scene_t *scene);
    void animate_mushroom(scene_t *scene, game_manager_t *manager, size_t i);
    void display_score(scene_t *scene, game_manager_t *manager);

    //////////////////////////////// INIT ///////////////////////////////////

    bool init_scene(scene_t *scene);
    bool load_music(scene_t *scene);
    bool get_player(scene_t *scene);
    void reset_player(scene_t *scene);
    bool map_loader(scene_t *scene, char *filepath);
    bool load_text_textures(scene_t *scene);

    /////////////////////////////// FREE ////////////////////////////////////

    void free_all(scene_t *scene, game_manager_t *manager);

    /////////////////////////////// MENU ////////////////////////////////////

    void menu_loop(scene_t *scene, game_manager_t *manager);
#endif
