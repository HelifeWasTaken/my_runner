/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** menu_loop
*/

#include <my_runner/runner.h>
#include <my_runner/scene.h>

void check_key_press_menu(scene_t *scene, game_manager_t *manager)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) || sfKeyboard_isKeyPressed(sfKeyDown))
        scene->menu.choice = !scene->menu.choice;
    if (sfKeyboard_isKeyPressed(sfKeyEnter) ||
        sfKeyboard_isKeyPressed(sfKeySpace))
        manager->state = (scene->menu.choice == GAME_CHOICE) ? GAME : QUIT;
}

void check_menu_event(scene_t *scene, game_manager_t *manager)
{
    while (sfRenderWindow_pollEvent(manager->window, &manager->event)) {
        if (manager->event.type == sfEvtKeyPressed)
            check_key_press_menu(scene, manager);
        if (manager->event.type == sfEvtClosed)
            manager->state = QUIT;
    }
}

void draw_cursor(scene_t *scene, game_manager_t *manager)
{
    const sfIntRect player_idle_frames[6] = {
        IRECT(1, 18, 12, 14), IRECT(16, 17, 13, 13), IRECT(32, 17, 13, 15),
        IRECT(49, 17, 12, 15), IRECT(65, 17, 12, 13), IRECT(81, 18, 12, 14)};

    if (scene->menu.choice == GAME_CHOICE) {
        sfSprite_setPosition(scene->player.sprite,
            VECF(WIN_W - 850, WIN_H - 400));
    } else {
        sfSprite_setPosition(scene->player.sprite,
            VECF(WIN_W - 850, WIN_H - 300));
    }
    animate_sprite(player_idle_frames, scene->player.sprite,
        &scene->player.frame, manager->clock);
    DRAW_SPRITE(manager->window, scene->player.sprite);
}

void animate_menu(scene_t *scene,  game_manager_t *manager)
{
    CLEAR_WINDOW(manager->window);
    DRAW_SPRITE(manager->window, scene->menu.sprite_bg);
    DRAW_SPRITE(manager->window, scene->menu.sprite_logo);
    draw_cursor(scene, manager);
    DRAW_SPRITE(manager->window, scene->menu.sprite_b1);
    DRAW_SPRITE(manager->window, scene->menu.sprite_b2);
    DISPLAY_WINDOW(manager->window);
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