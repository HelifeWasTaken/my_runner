/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** init_manager
*/

#include <my_runner/runner.h>

bool init_manager(game_manager_t *manager, char *file)
{
    manager->screen_size = VECU(1300, 768);
    manager->clock = sfClock_create();
    manager->score = 0;
    manager->state = MENU;
    manager->map = my_strdup(file);
    manager->type_window = LARGE;
    return (true);
}
