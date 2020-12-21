/*
** EPITECH PROJECT, 2020
** draw_all_game.c
** File description:
** draw_game
*/

#include <my_runner/scene.h>
#include <my_runner/runner.h>

void display_enemy(scene_t *scene, game_manager_t *manager)
{
    void (*enemy_anim[4])(scene_t *, game_manager_t *, size_t i) =
    {0, 0, &animate_mushroom, &animate_slime};
    for (size_t i = 0; scene->enemy[i].enemy_id != -2; i++) {
        if (scene->enemy[i].enemy_id == -1)
            continue;
        (*enemy_anim[scene->enemy[i].enemy_id])(scene, manager, i);
        sfSprite_setPosition(scene->enemy[i].sprite,
                scene->enemy[i].info.pos);
        DRAW_SPRITE(manager->window, scene->enemy[i].sprite);
    }
}

void draw_all_game(scene_t *scene, game_manager_t *manager)
{
    CLEAR_WINDOW(manager->window);
    draw_background(scene, manager);
    draw_parralax(scene, manager);
    draw_player(scene, manager);
    display_enemy(scene, manager);
    DISPLAY_WINDOW(manager->window);
}
