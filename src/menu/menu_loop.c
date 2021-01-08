/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** menu_loop
*/

#include <my_runner/runner.h>
#include <my_runner/scene.h>

static void change_player(scene_t *scene)
{
    if (scene->player.player_type == NB_PLAYER_SPRITES - 1)
        scene->player.player_type = 0;
    else
        scene->player.player_type++;
    SET_TEXTURE(scene->player.sprite,
        scene->player.texture[scene->player.player_type]);
}

static void resize_window(scene_t *scene, game_manager_t *manager)
{
    sfVector2u mode[3] = {
        VECU(800, WIN_H),
        VECU(1000, WIN_H),
        VECU(1300, WIN_H)};

    manager->type_window++;
    if (manager->type_window == 3)
        manager->type_window = 0;
    manager->screen_size = mode[manager->type_window];
    free_all(scene, manager, false);
    sfRenderWindow_close(manager->window);
    manager->window = CREATE_WINDOW(WIN_MODE_2, "my_runner");
    SET_FRAME_LIMIT(manager->window, 60);
    init_scene(scene, manager);
    sfMusic_play(scene->menu.music);
}

static void check_key_press_menu(scene_t *scene, game_manager_t *manager)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) ||
        sfKeyboard_isKeyPressed(sfKeyDown)) {
        scene->menu.choice = !scene->menu.choice;
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
        manager->state = (scene->menu.choice == GAME_CHOICE) ? GAME : QUIT;
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyF1)) {
        resize_window(scene, manager);
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyF2)) {
        change_player(scene);
        return;
    }
    manager->map = handle_keyboard(manager->map);
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
    sfMusic_pause(scene->menu.music);
}