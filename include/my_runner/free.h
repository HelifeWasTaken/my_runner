/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** free
*/

#pragma once

#ifndef __MY__RUNNER__FREE_H__
    #define __MY__RUNNER__FREE__H__
    #include <my_runner/scene.h>
    #include <my_runner/runner.h>
    void destroy_music(scene_t *scene);
    void destroy_world(scene_t *scene);
    void destroy_volcano_world(scene_t *scene);
    void destroy_forest_world(scene_t *scene);
    void destroy_enemy_textures(scene_t *scene);
    void destroy_player(scene_t *scene);
    void destroy_snow_world(scene_t *scene);
    void destroy_enemy_array(scene_t *scene);
    void destroy_menu(scene_t *scene);
    void destroy_manager(game_manager_t *manager);
    void destroy_end(scene_t *scene);
#endif
