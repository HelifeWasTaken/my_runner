/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** destroy_manager
*/

#include <my_runner/free.h>

void destroy_manager(game_manager_t *manager)
{
    if (manager->clock)
        sfClock_destroy(manager->clock);
    if (manager->window)
        sfRenderWindow_close(manager->window);
}