/*
** EPITECH PROJECT, 2020
** draw_player.c
** File description:
** draw_the_player
*/

#include <my_runner/scene.h>
#include <my_runner/runner.h>
#include <my_runner/gravity.h>

/*
static void update_jump(scene_t *scene)
{
    const sfVector2f player_jump_velocity[8] = {
        VECF(2, -0.7f), VECF(2.2f, -1.5f), VECF(2.5f, -1.8f), VECF(2.7f, -2),
        VECF(2.9f, -2.3f), VECF(3, -2.5f), VECF(3.2f, -2.8),
    };

    if (scene->player.pos.y <= 600) {
        scene->player.state = PLAYER_FALL;
        return;
    } else {
        scene->player.pos.x +=
            player_jump_velocity[scene->player.frame.frame].x;
        scene->player.pos.y +=
            player_jump_velocity[scene->player.frame.frame].y * 2;
    }
}

static void update_fall(scene_t *scene)
{
    const sfVector2f player_fall_velocity[8] = {
        VECF(2, 0), VECF(2.2f, 0), VECF(2.2f, 0), VECF(2.2f, 0.5f),
        VECF(2.2f, 0.79f), VECF(2.2f, 1.2f), VECF(2.2f, 2.3f), VECF(2.2f, 4)
    };

    if (scene->player.pos.y > GROUND_HEIGHT) {
        scene->player.state = PLAYER_IDLE;
        return;
    } else {
        scene->player.pos.x +=
            player_fall_velocity[scene->player.frame.frame].x;
        scene->player.pos.y +=
            player_fall_velocity[scene->player.frame.frame].y * 2;
    }
}
*/

static void animate_jump(scene_t *scene, game_manager_t *manager)
{
    const sfIntRect player_jump_frames[8] = {
        IRECT(12, 190, 12, 17), IRECT(48, 190, 12, 17), IRECT(84, 189, 12, 17),
        IRECT(10, 224, 13, 18), IRECT(47, 222, 12, 19), IRECT(85, 223, 12, 19),
        IRECT(13, 261, 10, 18), IRECT(48, 261, 11, 19)
    };
    sfTime time_struct = sfClock_getElapsedTime(manager->clock);
    float seconds = sfTime_asSeconds(time_struct);

/*
    if (scene->player.state == PLAYER_JUMP)
        update_jump(scene);
    else
        update_fall(scene);
*/
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
