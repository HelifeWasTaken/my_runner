/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** animate_ninja
*/

#include <my_runner/runner.h>
#include <my_runner/scene.h>

static bool should_ninja_attack(scene_t *scene, size_t i)
{
    if (scene->player.info.pos.x <
            scene->enemy[i].info.pos.x &&
            scene->enemy[i].info.pos.x -
            scene->player.info.pos.x < 400 &&
            scene->enemy[i].state == IDLE) {
        scene->enemy[i].state = ACTION;
        scene->enemy[i].info.state = JUMPING;
        scene->enemy[i].frame.frame = 0;
        scene->enemy[i].frame.frame_max = 4;
        return (true);
    }
    return (false);
}

static void animate_ninja_idle(scene_t *scene, game_manager_t *manager,
    size_t i)
{
    const sfIntRect ninja_idle_frames[8] = {
        IRECT(402, 70, 15, 26), IRECT(353, 72, 17, 24), IRECT(305, 71, 17, 25),
        IRECT(257, 71, 13, 25), IRECT(210, 70, 14, 26), IRECT(159, 72, 19, 24),
        IRECT(113, 71, 18, 25), IRECT(65, 71, 14, 25)};

    if (should_ninja_attack(scene, i))
        return;
    animate_sprite(ninja_idle_frames, scene->enemy[i].sprite,
        &scene->enemy[i].frame, manager->clock);
    scene->enemy[i].info.pos.x -= 10;
}

static void animate_ninja_attack(scene_t *scene, game_manager_t *manager,
    size_t i)
{
    const sfIntRect ninja_attack_frames[8] = {
        IRECT(398, 312, 16, 24), IRECT(336, 313, 37, 23),
        IRECT(294, 314, 32, 22), IRECT(253, 314, 28, 22)};

    if (scene->enemy[i].info.pos.x < scene->player.info.pos.x) {
        scene->enemy[i].state = IDLE;
        scene->enemy[i].info.state = ON_GROUND;
        scene->enemy[i].frame.frame = 0;
        scene->enemy[i].frame.frame_max = 8;
    }
    animate_sprite(ninja_attack_frames, scene->enemy[i].sprite,
        &scene->enemy[i].frame, manager->clock);
    scene->enemy[i].info.pos.x -= 15;
}

void animate_ninja(scene_t *scene, game_manager_t *manager, size_t i)
{
    if (scene->enemy[i].info.state == ON_GROUND)
        animate_ninja_idle(scene, manager, i);
    else
        animate_ninja_attack(scene, manager, i);
}