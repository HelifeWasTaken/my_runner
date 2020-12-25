/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** scene
*/

#pragma once

#ifndef __RUNNER__SCENE__H__
    #define __RUNNER__SCENE__H__
    #include <my_runner/player.h>
    #include <my_runner/world.h>
    #include <my_runner/enemy.h>
    #include <my_runner/runner.h>
    #include <my_runner/music.h>
    #include <my_runner/font.h>
    #include <my_runner/menu.h>
    #include <my_runner/end.h>

    typedef struct scene {
        menu_t menu;
        world_t world;
        music_t music;
        sfTexture **enemy_texture;
        player_t player;
        enemy_t *enemy;
        text_t text;
        end_t end;
    } scene_t;

    /////////////////////////////// GAME ///////////////////////////////////

    void game_loop(scene_t *scene, game_manager_t *manager);
    void draw_player(scene_t *scene, game_manager_t *manager);
    void draw_all_game(scene_t *scene, game_manager_t *manager);
    void animate_slime(scene_t *scene, game_manager_t *manager, size_t i);
    void animate_mushroom(scene_t *scene, game_manager_t *manager, size_t i);
    void animate_ninja(scene_t *scene, game_manager_t *manager, size_t i);
    bool check_if_overlap(scene_t *scene, size_t i);
    void set_game_as_lose(scene_t *scene);

    /////////////////////////// WORLD GAME ////////////////////////////////

    void draw_volcano(scene_t *scene, game_manager_t *manager);
    void draw_forest(scene_t *scene, game_manager_t *manager);
    int8_t change_world(int8_t old_choice);

    //////////////////////////////// INIT ///////////////////////////////////

    bool init_scene(scene_t *scene);
    bool load_music(scene_t *scene);
    bool get_player(scene_t *scene);
    void reset_player(scene_t *scene);
    bool map_loader(scene_t *scene, char *filepath);
    bool load_enemy_textures(scene_t *scene);
    bool load_text_textures(scene_t *scene);
    bool load_end(scene_t *scene);
    bool load_menu(scene_t *scene);
    bool init_manager(game_manager_t *manager, char *file);

    bool get_background(scene_t *scene);
    bool get_volcano_background(scene_t *scene);

    bool get_parralax_texture(scene_t *scene);
    bool get_forest_parralax(scene_t *scene);
    bool get_volcano_parralax(scene_t *scene);
    bool get_snow_parralax(scene_t *scene);

    ////////////////////////// GETTER SETTER  /////////////////////////////

    enemy_t get_empty_enemy(u_int8_t id);
    void prepare_infinity_position(scene_t *scene);
    bool prepare_map_positions(scene_t *scene, char *file);
    void get_mushroom(enemy_t **new, int enemy_id, size_t i);
    void get_slime(enemy_t **new, int enemy_id, size_t i);
    void get_ninja(enemy_t **new, int enemy_id, size_t i);

    /////////////////////////////// FREE ////////////////////////////////////

    void free_all(scene_t *scene, game_manager_t *manager);

    /////////////////////////////// MENU ////////////////////////////////////

    void menu_loop(scene_t *scene, game_manager_t *manager);
    void animate_menu(scene_t *scene,  game_manager_t *manager);
    void draw_menu_cursor(scene_t *scene, game_manager_t *manager);

    /////////////////////////////// END ////////////////////////////////////

    void end_loop(scene_t *scene, game_manager_t *manager);
    void animate_end(scene_t *scene, game_manager_t *manager);

    ////////////////////////////////////////////////////////////////////////

    void display_info(sfText *text, sfRenderWindow *window,
        char *s1, char *s2);
#endif
