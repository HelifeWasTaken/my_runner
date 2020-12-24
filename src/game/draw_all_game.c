/*
** EPITECH PROJECT, 2020
** draw_all_game.c
** File description:
** draw_game
*/

#include <my_runner/scene.h>
#include <my_runner/runner.h>

bool check_if_overlap(scene_t *scene, size_t i)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(scene->player.sprite);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(scene->enemy[i].sprite);

    return (
            sfFloatRect_contains(&rect, rect2.left, rect2.top) ||
            sfFloatRect_contains(&rect, rect2.left + rect2.width, rect2.top) ||
            sfFloatRect_contains(&rect, rect2.left, rect2.top + rect2.height) ||
            sfFloatRect_contains(&rect, rect2.left + rect2.width,
                rect2.height + rect2.top)
           );
}

void set_game_as_lose(scene_t *scene)
{
    sfSound_play(scene->music.player_death.sound);
    sfMusic_stop(scene->music.game);
    scene->player.info.state = DYING;
    scene->player.frame.frame = 0;
}

static void display_enemy(scene_t *scene, game_manager_t *manager)
{
    bool map_end = true;
    void (*enemy_anim[4])(scene_t *, game_manager_t *, size_t i) =
    {0, 0, &animate_mushroom, &animate_slime};

    if (scene->player.info.state == DYING)
        return;
    for (size_t i = 0; scene->enemy[i].enemy_id != -2; i++) {
        if (scene->enemy[i].enemy_id == -1 || scene->enemy[i].info.pos.x < -400)
            continue;
        map_end = false;
        if (scene->player.info.state != DYING && check_if_overlap(scene, i))
            set_game_as_lose(scene);
        (*enemy_anim[scene->enemy[i].enemy_id])(scene, manager, i);
        sfSprite_setPosition(scene->enemy[i].sprite,
                scene->enemy[i].info.pos);
        DRAW_SPRITE(manager->window, scene->enemy[i].sprite);
    }
    if (map_end)
        scene->player.info.state = WIN;
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
