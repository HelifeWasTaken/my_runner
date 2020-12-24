/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** end_loop
*/

#include <my_runner/scene.h>
#include <my_runner/runner.h>

static void check_key_press_end(game_manager_t *manager)
{
    if (sfKeyboard_isKeyPressed(sfKeyEnter) ||
            sfKeyboard_isKeyPressed(sfKeySpace))
        manager->state = MENU;
}

static void check_end_event(game_manager_t *manager)
{
    while (sfRenderWindow_pollEvent(manager->window, &manager->event)) {
        if (manager->event.type == sfEvtKeyPressed)
            check_key_press_end(manager);
        if (manager->event.type == sfEvtClosed)
            manager->state = QUIT;
    }
}

void end_loop(scene_t *scene, game_manager_t *manager)
{
    reset_player(scene);
    sfText_setPosition(scene->text.text_score, VECF(530, WIN_H + 300));
    sfSprite_setPosition(scene->menu.sprite_b2,
            VECF(WIN_W - 770, WIN_H - 400 + 300 + 300 - 20));
    sfSprite_setPosition(scene->player.sprite,
            VECF(WIN_W - 820, WIN_H - 300 + 300 + 213 - 20));
    sfMusic_play(scene->end.music);
    while (sfRenderWindow_isOpen(manager->window) && manager->state == END) {
        check_end_event(manager);
        animate_end(scene, manager);
    }
    reset_player(scene);
    sfSprite_setPosition(scene->menu.sprite_b2, VECF(WIN_W - 760, WIN_H - 300));
    sfText_setPosition(scene->text.text_score, VECF(25, 25));
    sfMusic_stop(scene->end.music);
}
