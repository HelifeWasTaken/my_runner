/*
** EPITECH PROJECT, 2020
** draw_all_game.c
** File description:
** draw_game
*/

#include <my_runner/scene.h>
#include <my_runner/runner.h>

static void animate_enemy(scene_t *scene, game_manager_t *manager, size_t i)
{
    void (*enemy_anim[4])(scene_t *, game_manager_t *, size_t i) =
        {0, 0, &animate_mushroom, &animate_slime};

    (*enemy_anim[scene->enemy[i].enemy_id])(scene, manager, i);
    sfSprite_setPosition(scene->enemy[i].sprite,
            scene->enemy[i].info.pos);
    DRAW_SPRITE(manager->window, scene->enemy[i].sprite);
}

static void display_enemy(scene_t *scene, game_manager_t *manager)
{
    bool map_end = true;

    if (scene->player.info.state == DYING)
        return;
    for (size_t i = 0; scene->enemy[i].enemy_id != -2; i++) {
        if (scene->enemy[i].enemy_id == -1 || scene->enemy[i].info.pos.x < -400)
            continue;
        map_end = false;
        if (scene->player.info.state != DYING && check_if_overlap(scene, i))
            set_game_as_lose(scene);
        animate_enemy(scene, manager, i);
    }
    if (map_end && scene->player.info.state == ON_GROUND) {
        if (manager->infinty_enabled)
            prepare_infinity_position(scene);
        else
            scene->player.info.state = WIN;
    }
}

void draw_all_game(scene_t *scene, game_manager_t *manager)
{
    if (scene->player.info.state != DYING) {
        CLEAR_WINDOW(manager->window);
        draw_background(scene, manager);
        draw_parralax(scene, manager);
        display_enemy(scene, manager);
    } else
        sfRenderWindow_clear(manager->window, sfRed);
    draw_player(scene, manager);
    display_score(scene, manager);
    DISPLAY_WINDOW(manager->window);
}
