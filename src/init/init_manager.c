/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** init_manager
*/

#include <my_runner/runner.h>

bool init_manager(game_manager_t *manager, char *file)
{
    manager->window = CREATE_WINDOW(WIN_MODE, WINDOW_NAME);
    if (!manager->window)
        return (false);
    SET_FRAME_LIMIT(manager->window, 60);
    manager->clock = sfClock_create();
    manager->score = 0;
    manager->state = END;
    manager->map = my_strdup(file);
    return (true);
}