/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** get_empty_enemy
*/

#include <my_runner/scene.h>

enemy_t get_empty_enemy(u_int8_t id)
{
    frame_t empty_frame = {0};
    entity_t empty_entity = {0};

    return ((enemy_t){empty_frame, NULL, id, IDLE, empty_entity});
}

