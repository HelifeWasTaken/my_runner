/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** end_loop
*/

#include <my_runner/scene.h>
#include <my_runner/runner.h>

static void check_key_press_end(game_manager_t *manager, scene_t *scene)
{
    char *tmp = NULL;

    if (sfKeyboard_isKeyPressed(sfKeyEnter) ||
            sfKeyboard_isKeyPressed(sfKeySpace))
        manager->state = MENU;
    else if (manager->infinty_enabled) {
        scene->end.username = handle_keyboard(scene->end.username);
        if (scene->end.username)
            tmp = concat_string(my_strdup("Username: "),
                my_strdup(scene->end.username));
        else
            tmp = my_strdup("Username: ");
        sfText_setString(scene->end.username_text, tmp);
        free(tmp);
    }
}

static void check_end_event(game_manager_t *manager, scene_t *scene)
{
    while (sfRenderWindow_pollEvent(manager->window, &manager->event)) {
        if (manager->event.type == sfEvtKeyPressed)
            check_key_press_end(manager, scene);
        if (manager->event.type == sfEvtClosed)
            manager->state = QUIT;
    }
}

static void preset_end_v2(game_manager_t *manager, scene_t *scene)
{
    sfText_setPosition(scene->end.score_board,
        (manager->infinty_enabled) ?
            VECF(500, WIN_H - 200) : VECF(150, WIN_H - 100));
    sfText_setString(scene->end.score_board, scene->end.top_str);
    sfText_setPosition(scene->text.text_score, VECF(530, WIN_H + 300));
    sfText_setPosition(scene->end.username_text, VECF(100, 530));
    sfSprite_setPosition(scene->menu.sprite_b2,
            VECF(WIN_W - 770, WIN_H - 400 + 300 + 300 - 20));
    sfSprite_setPosition(scene->player.sprite,
            VECF(WIN_W - 820, WIN_H - 300 + 300 + 213 - 20));
    sfMusic_play(scene->end.music);
}

static void preset_end(game_manager_t *manager, scene_t *scene)
{
    if (manager->infinty_enabled) {
        if (scene->end.top_str)
            free(scene->end.top_str);
        scene->end.top_str = get_leaderboard_in_str();
        sfText_setString(scene->end.username_text, "Username: ");
    } else
        scene->end.top_str = "Scoreboard avaiable only in infinite mode";
    if (scene->end.username) {
        scene->end.username = NULL;
        free(scene->end.username);
    }
    preset_end_v2(manager, scene);
}

void end_loop(scene_t *scene, game_manager_t *manager)
{
    reset_player(scene);
    preset_end(manager, scene);
    while (sfRenderWindow_isOpen(manager->window) && manager->state == END) {
        check_end_event(manager, scene);
        animate_end(scene, manager);
    }
    if (manager->infinty_enabled)
        append_score_to_file(manager->score, scene->end.username);
    reset_player(scene);
    sfSprite_setPosition(scene->menu.sprite_b2, VECF(WIN_W - 760, WIN_H - 300));
    sfText_setPosition(scene->text.text_score, VECF(25, 25));
    sfMusic_stop(scene->end.music);
}