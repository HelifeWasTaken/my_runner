/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <my_runner/runner.h>
#include <my_runner/scene.h>
#include <my_stdio.h>
#include <my_runner/free.h>

int main(int ac, char **av)
{
    void (*game_ptr[4])(scene_t *, game_manager_t *) = {
        &menu_loop, &game_loop, &end_loop, &free_all};
    int usage_return = 0;
    game_manager_t manager = {0};
    scene_t scene = {0};

    usage_return = usage(ac, av);
    if (usage_return == 0 || usage_return == -1)
        return ((usage_return == 0) ? 0 : 84);
    manager.infinty_enabled = (usage_return == 2) ? true : false;
    if (init_scene(&scene) == false || init_manager(&manager, av[1]) == false) {
        free_all(&scene, &manager);
        return (84);
    }
    while (sfRenderWindow_isOpen(manager.window))
        (*game_ptr[manager.state])(&scene, &manager);
    return (0);
}
