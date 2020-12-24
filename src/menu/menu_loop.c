/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** menu_loop
*/

#include <my_runner/runner.h>
#include <my_runner/scene.h>

static void check_key_press_menu(scene_t *scene, game_manager_t *manager)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) || sfKeyboard_isKeyPressed(sfKeyDown))
        scene->menu.choice = !scene->menu.choice;
    if (sfKeyboard_isKeyPressed(sfKeyEnter) ||
        sfKeyboard_isKeyPressed(sfKeySpace))
        manager->state = (scene->menu.choice == GAME_CHOICE) ? GAME : QUIT;
}

static void check_menu_event(scene_t *scene, game_manager_t *manager)
{
    while (sfRenderWindow_pollEvent(manager->window, &manager->event)) {
        if (manager->event.type == sfEvtKeyPressed)
            check_key_press_menu(scene, manager);
        if (manager->event.type == sfEvtClosed)
            manager->state = QUIT;
    }
}

void menu_loop(scene_t *scene, game_manager_t *manager)
{
    sfMusic_play(scene->menu.music);
    while (sfRenderWindow_isOpen(manager->window) && manager->state == MENU) {
        check_menu_event(scene, manager);
        animate_menu(scene, manager);
    }
    sfMusic_stop(scene->menu.music);
}