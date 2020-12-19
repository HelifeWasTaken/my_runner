/*
** EPITECH PROJECT, 2020
** draw_player.c
** File description:
** draw_the_player
*/

#include <my_runner/scene.h>
#include <my_runner/runner.h>
#include <my_runner/gravity.h>

static void animate_jump(scene_t *scene, game_manager_t *manager)
{
    sfTime time_struct = sfClock_getElapsedTime(manager->clock);
    float seconds = sfTime_asSeconds(time_struct);
    const sfIntRect player_jump_frames[8] = {
        IRECT(12, 190, 12, 17), IRECT(48, 190, 12, 17), IRECT(84, 189, 12, 17),
        IRECT(10, 224, 13, 18), IRECT(47, 222, 12, 19), IRECT(85, 223, 12, 19),
        IRECT(13, 261, 10, 18), IRECT(48, 261, 11, 19)
    };

    handle_gravity(&scene->player.info);
    if (seconds > scene->player.frame.elapsed_time + TIME_SHIFT_PLAYER_JUMP) {
        scene->player.frame.elapsed_time = seconds;
        (scene->player.frame.frame)++;
        if (scene->player.frame.frame > PLAYER_FRAME_HEIGHT)
            scene->player.frame.frame = PLAYER_FRAME_ONE;
    }
    sfSprite_setTextureRect(scene->player.sprite,
            player_jump_frames[scene->player.frame.frame]);
}

static void animate_idle_run(scene_t *scene, game_manager_t *manager)
{
    const sfIntRect player_idle_frames[8] = {
        IRECT(12, 45, 12, 17), IRECT(48, 45, 12, 17), IRECT(84, 45, 12, 17),
        IRECT(12, 82, 12, 17), IRECT(48, 82, 12, 17), IRECT(84, 82, 12, 17),
        IRECT(12, 117, 12, 17), IRECT(48, 117, 12, 17)
    };
    sfTime time_struct = sfClock_getElapsedTime(manager->clock);
    float seconds = sfTime_asSeconds(time_struct);

    if (seconds > scene->player.frame.elapsed_time +
            TIME_SHIFT_PLAYER_IDLE) {
        scene->player.frame.elapsed_time = seconds;
        (scene->player.frame.frame)++;
        if (scene->player.frame.frame > PLAYER_FRAME_HEIGHT)
            scene->player.frame.frame = PLAYER_FRAME_ONE;
    }
    if (scene->player.info.entity_position.x > 50)
        scene->player.info.entity_position.x -= 2;
    sfSprite_setTextureRect(scene->player.sprite,
            player_idle_frames[scene->player.frame.frame]);
}

void draw_player(scene_t *scene, game_manager_t *manager)
{
    if (scene->player.info.state == ON_GROUND)
        animate_idle_run(scene, manager);
    else
        animate_jump(scene, manager);
    sfSprite_setPosition(scene->player.sprite,
            scene->player.info.entity_position);
    DRAW_SPRITE(manager->window, scene->player.sprite);
}
