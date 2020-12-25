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
        {0, &animate_ninja, &animate_mushroom, &animate_slime};

    (*enemy_anim[scene->enemy[i].enemy_id])(scene, manager, i);
    sfSprite_setPosition(scene->enemy[i].sprite,
            scene->enemy[i].info.pos);
    DRAW_SPRITE(manager->window, scene->enemy[i].sprite);
}

static void display_enemy(scene_t *scene, game_manager_t *manager)
{
    bool map_end = true;

    if (scene->player.info.state == DYING || scene->player.info.state == INIT)
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
        scene->player.info.state = WIN;
        scene->player.info.pos.y = PLAYER_GROUND_HEIGHT;
    }
}

void draw_snow(scene_t *scene, game_manager_t *manager)
{
    sfTime time_struct = sfClock_getElapsedTime(manager->clock);
    float seconds = sfTime_asSeconds(time_struct);

    FOR_EACH_PARRALAX(i, NB_PARA_SNOW) {
        sfSprite_setTextureRect(scene->world.snow.para[i].layer,
            IRECT(seconds * (i * 30) + i * 30 + 5 + 120, 0, 512, 256));
        DRAW_SPRITE(manager->window, scene->world.snow.para[i].layer);
    }
}

void draw_all_game(scene_t *scene, game_manager_t *manager)
{
    void (*ptr_world[3])(scene_t *, game_manager_t *) =
        {&draw_volcano, &draw_forest, &draw_snow};

    if (scene->player.info.state != DYING) {
        CLEAR_WINDOW(manager->window);
        (ptr_world[scene->world.choice])(scene, manager);
        if (scene->player.info.state != INIT)
            display_enemy(scene, manager);
    } else
        sfRenderWindow_clear(manager->window, sfRed);
    draw_player(scene, manager);
    display_info(scene->text.text_score, manager->window,
        my_strdup("score: "), my_itoa(manager->score, "0123456789"));
    DISPLAY_WINDOW(manager->window);
}
