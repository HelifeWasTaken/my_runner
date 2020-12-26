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

static int init_everything(int ac, char **av,
    game_manager_t *manager, scene_t *scene)
{
    int usage_return = 0;
    usage_return = usage(ac, av);
    if (usage_return == 0 || usage_return == -1)
        return ((usage_return == 0) ? 0 : 84);
    manager->infinty_enabled = (usage_return == 2) ? true : false;
    if (!init_manager(manager, av[1]) || !init_scene(scene, manager)) {
        free_all(scene, manager, true);
        return (84);
    }
    return (1);
}

int main(int ac, char **av)
{
    void (*game_ptr[4])(scene_t *, game_manager_t *) = {
        &menu_loop, &game_loop, &end_loop};
    game_manager_t manager = {0};
    scene_t scene = {0};
    int return_init = init_everything(ac, av, &manager, &scene);

    if (return_init == 0)
        return (0);
    if (return_init == 84)
        return (84);
    manager.window = CREATE_WINDOW(WIN_MODE, WINDOW_NAME);
    if (manager.window == NULL)
        return (84);
    SET_FRAME_LIMIT(manager.window, 60);
    while (sfRenderWindow_isOpen(manager.window) && manager.state != QUIT)
        (*game_ptr[manager.state])(&scene, &manager);
    free_all(&scene, &manager, true);
    return (0);
}
