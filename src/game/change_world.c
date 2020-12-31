/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** change_world
*/

#include <my_runner/scene.h>

int8_t change_world(int8_t old_choice)
{
    int8_t new_choice = 0;

    srand(time(NULL));
    new_choice = rand() % NB_WORLD;
    while (new_choice == old_choice)
        new_choice = rand() % NB_WORLD;
    return (new_choice);
}
