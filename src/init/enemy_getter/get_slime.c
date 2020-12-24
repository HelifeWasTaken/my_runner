/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** get_slime
*/

#include <my_runner/scene.h>

void get_slime(enemy_t **new, int enemy_id, size_t i)
{
    (*new)[i].frame = FRAME_SET(0, 5, SLIME_TIME_SHIFT);
    (*new)[i].enemy_id = enemy_id;
    (*new)[i].state = IDLE;
    (*new)[i].info = (entity_t){
        VECF(-0.5f, 0.5f),
        4,
        VECF(0, 0),
        MIN_MAX_FLOAT(GROUND_HEIGHT_SLIME, GROUND_HEIGHT_SLIME - 60),
        VECF(WIN_W + 200, 0),
        ON_GROUND
    };
}