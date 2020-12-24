/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** animate_slime
*/

#include <my_runner/runner.h>
#include <my_runner/scene.h>

static bool should_slime_jump(scene_t *scene, size_t i)
{
    if (scene->player.info.pos.x <
            scene->enemy[i].info.pos.x &&
            scene->enemy[i].info.pos.x -
            scene->player.info.pos.x < 200 &&
            scene->enemy[i].state == IDLE) {
        scene->enemy[i].state = ACTION;
        scene->enemy[i].info.state = JUMPING;
        scene->enemy[i].frame.frame = 0;
        scene->enemy[i].frame.frame_max = 15;
        return (true);
    }
    return (false);
}

static void animate_idle(scene_t *scene, game_manager_t *manager, size_t i)
{
    const sfIntRect slime_idle_frames[5] = {
        IRECT(1, 53, 14, 11), IRECT(17, 53, 14, 11), IRECT(33, 52, 14, 11),
        IRECT(49, 54, 13, 10), IRECT(65, 53, 14, 11)};

    if (should_slime_jump(scene, i)) {
        return;
    }
    animate_sprite(slime_idle_frames, scene->enemy[i].sprite,
        &scene->enemy[i].frame, manager->clock);
    scene->enemy[i].info.pos.y = GROUND_HEIGHT_SLIME;
    scene->enemy[i].info.pos.x -= 10;
}

static void animate_jump(scene_t *scene, game_manager_t *manager, size_t i)
{
    const sfIntRect slime_jump_frames[16] = {
        IRECT(1, 20, 14, 12), IRECT(17, 20, 14, 12), IRECT(33, 22, 14, 10),
        IRECT(48, 23, 16, 9), IRECT(66, 19, 12, 13), IRECT(82, 18, 12, 13),
        IRECT(97, 16, 13, 12), IRECT(113, 13, 13, 13), IRECT(129, 12, 13, 14),
        IRECT(145, 14, 13, 16), IRECT(161, 16, 13, 14), IRECT(177, 18, 13, 14),
        IRECT(193, 21, 14, 11), IRECT(208, 23, 16, 9), IRECT(208, 23, 16, 9),
        IRECT(225, 22, 14, 10)};

    if (handle_gravity(&scene->enemy[i].info)) {
        scene->enemy[i].state = IDLE;
        scene->enemy[i].frame.frame_max = 5;
        return;
    }
    animate_sprite(slime_jump_frames, scene->enemy[i].sprite,
        &scene->enemy[i].frame, manager->clock);
}

void animate_slime(scene_t *scene, game_manager_t *manager, size_t i)
{
    if (scene->enemy[i].state == IDLE)
        animate_idle(scene, manager, i);
    else
        animate_jump(scene, manager, i);
}
