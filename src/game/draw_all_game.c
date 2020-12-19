/*
** EPITECH PROJECT, 2020
** draw_all_game.c
** File description:
** draw_game
*/

#include <my_runner/scene.h>
#include <my_runner/runner.h>

void animate_mushroom(scene_t *scene, game_manager_t *manager, size_t i)
{
    sfTime time_struct  = sfClock_getElapsedTime(manager->clock);
    float seconds = sfTime_asSeconds(time_struct);
    const sfIntRect mushroom_frames[8] = {
        IRECT(113, 0, 14, 15), IRECT(97, 0, 14, 16), IRECT(82, 0, 12, 16),
        IRECT(65, 2, 14, 14), IRECT(49, 0, 14, 16), IRECT(33, 0, 14, 16),
        IRECT(18, 0, 12, 16), IRECT(1, 2, 14, 14)
    };

    if (seconds >
        scene->map->enemy[i].frame.elapsed_time + MUSHROOM_TIME_SHIFT) {
        if (scene->map->enemy[i].frame.frame > MUSHROOM_FRAME_HEIGHT)
            scene->map->enemy[i].frame.frame = MUSHROOM_FRAME_ONE;
         sfSprite_setTextureRect(scene->map->enemy[i].sprite,
            mushroom_frames[scene->map->enemy[i].frame.frame]);
        (scene->map->enemy[i].frame.frame)++;
        scene->map->enemy[i].frame.elapsed_time = seconds;
    }
    scene->map->enemy[i].info.entity_position.y = GROUND_HEIGHT_MUSHROOM;
    scene->map->enemy[i].info.entity_position.x -= 10;
}

void animate_idle(scene_t *scene, game_manager_t *manager, size_t i)
{
    sfTime time_struct = sfClock_getElapsedTime(manager->clock);
    float seconds = sfTime_asSeconds(time_struct);
    const sfIntRect slime_idle_frames[8] = {
        IRECT(1, 53, 14, 11), IRECT(17, 53, 14, 11), IRECT(33, 52, 14, 11),
        IRECT(49, 54, 13, 10), IRECT(65, 53, 14, 11)
    };

    if (scene->player.info.entity_position.x <
        scene->map->enemy[i].info.entity_position.x &&
        scene->map->enemy[i].info.entity_position.x -
        scene->player.info.entity_position.x < 300 &&
        scene->map->enemy[i].state == IDLE) {
        scene->map->enemy[i].state = ACTION;
        scene->map->enemy[i].info.state = JUMPING;
        scene->map->enemy[i].frame.frame = MUSHROOM_FRAME_ONE;
        return;
    }
    if (seconds >
        scene->map->enemy[i].frame.elapsed_time + SLIME_TIME_SHIFT) {
        if (scene->map->enemy[i].frame.frame > SLIME_FRAME_FIVE)
            scene->map->enemy[i].frame.frame = SLIME_FRAME_ONE;
         sfSprite_setTextureRect(scene->map->enemy[i].sprite,
            slime_idle_frames[scene->map->enemy[i].frame.frame]);
        (scene->map->enemy[i].frame.frame)++;
        scene->map->enemy[i].frame.elapsed_time = seconds;
    }
    scene->map->enemy[i].info.entity_position.y = GROUND_HEIGHT_SLIME;
    scene->map->enemy[i].info.entity_position.x -= 10;
}

void animate_jump(scene_t *scene, game_manager_t *manager, size_t i)
{
    sfTime time_struct = sfClock_getElapsedTime(manager->clock);
    float seconds = sfTime_asSeconds(time_struct);
    const sfIntRect slime_jump_frames[16] = {
        IRECT(1, 20, 14, 12),   IRECT(17, 20, 14, 12),  IRECT(33, 22, 14, 10),
        IRECT(48, 23, 16, 9),   IRECT(66, 19, 12, 13),  IRECT(82, 18, 12, 13),
        IRECT(97, 16, 13, 12),  IRECT(113, 13, 13, 13), IRECT(129, 12, 13, 14),
        IRECT(145, 14, 13, 16), IRECT(161, 16, 13, 14), IRECT(177, 18, 13, 14),
        IRECT(193, 21, 14, 11), IRECT(208, 23, 16, 9),  IRECT(208, 23, 16, 9),
        IRECT(225, 22, 14, 10)
    };

    if (handle_gravity(&scene->map->enemy[i].info))
        scene->map->enemy[i].state = IDLE;
    if (seconds > scene->map->enemy[i].frame.elapsed_time + SLIME_TIME_SHIFT) {
        scene->map->enemy[i].frame.elapsed_time = seconds;
        (scene->map->enemy[i].frame.frame)++;
        if (scene->map->enemy[i].frame.frame > SLIME_FRAME_FOURTEEN)
            scene->map->enemy[i].frame.frame = SLIME_FRAME_ONE;
    }
    sfSprite_setTextureRect(scene->map->enemy[i].sprite,
        slime_jump_frames[scene->map->enemy[i].frame.frame]);
}

void animate_slime(scene_t *scene, game_manager_t *manager, size_t i)
{
    if (scene->map->enemy[i].state == IDLE)
        animate_idle(scene, manager, i);
    else
        animate_jump(scene, manager, i);
}

void display_enemy(scene_t *scene, game_manager_t *manager)
{
    void (*enemy_anim[4])(scene_t *, game_manager_t *, size_t i) =
        {0, 0, &animate_mushroom, &animate_slime};
    for (size_t i = 0; scene->map->enemy[i].enemy_id != -2; i++) {
        if (scene->map->enemy[i].enemy_id != -1) {
            (*enemy_anim[scene->map->enemy[i].enemy_id])(scene, manager, i);
            sfSprite_setPosition(scene->map->enemy[i].sprite,
                scene->map->enemy[i].info.entity_position);
            DRAW_SPRITE(manager->window, scene->map->enemy[i].sprite);
        }
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
