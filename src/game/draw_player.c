/*
** EPITECH PROJECT, 2020
** draw_player.c
** File description:
** draw_the_player
*/

#include <my_runner/scene.h>
#include <my_runner/runner.h>

static void animate_jump(scene_t *scene, game_manager_t *manager)
{
    const sfIntRect player_jump_frames[6] = {
        IRECT(2, 112, 12, 16), IRECT(18, 112, 12, 16), IRECT(35, 112, 11, 16),
        IRECT(1, 97, 12, 15), IRECT(18, 97, 11, 15), IRECT(33, 97, 45, 112)};

    if (handle_gravity(&scene->player.info)) {
        sfSound_play(scene->music.player_land.sound);
        scene->player.frame.offset = TIME_SHIFT_PLAYER_IDLE;
    }
    animate_sprite(player_jump_frames, scene->player.sprite,
            &scene->player.frame, manager->clock);
}

static void animate_idle_run(scene_t *scene, game_manager_t *manager)
{
    const sfIntRect player_idle_frames[6] = {
        IRECT(1, 18, 12, 14), IRECT(16, 17, 13, 13), IRECT(32, 17, 13, 15),
        IRECT(49, 17, 12, 15), IRECT(65, 17, 12, 13), IRECT(81, 18, 12, 14)};

    animate_sprite(player_idle_frames, scene->player.sprite,
            &scene->player.frame, manager->clock);
    if (scene->player.info.pos.x > 60)
        scene->player.info.pos.x -= 2;
}

static void animate_win(scene_t *scene, game_manager_t *manager)
{
    const sfIntRect player_dash_frames[6] = {
        IRECT(1, 32, 13, 16), IRECT(16, 32, 14, 16), IRECT(32, 32, 14, 16),
        IRECT(48, 32, 14, 16), IRECT(65, 34, 13, 14), IRECT(81, 34, 13, 14)};

    scene->player.frame.frame_max = 6;
    scene->player.frame.offset = TIME_SHIFT_PLAYER_IDLE;
    if (scene->player.info.pos.x < WIN_W + 300) {
        animate_sprite(player_dash_frames, scene->player.sprite,
                &scene->player.frame, manager->clock);
        scene->player.info.pos.x += 15;
    }
    else
        manager->state = MENU;
}

static void animate_die(scene_t *scene, game_manager_t *manager)
{
    const sfIntRect player_die_frames[8] = {
        IRECT(4, 3, 9, 16), IRECT(20, 4, 8, 10), IRECT(37, 5, 7, 6),
        IRECT(52, 4, 9, 8), IRECT(68, 3, 11, 10), IRECT(84, 2, 11, 14),
        IRECT(100, 2, 11, 12), IRECT(115, 1, 13, 14)};

    scene->player.frame.frame_max = 8;
    scene->player.frame.offset = 0.45f;
    if (scene->player.frame.frame != 7)
        animate_sprite(player_die_frames, scene->player.sprite,
                &scene->player.frame, manager->clock);
    else
        manager->state = MENU;
}

void draw_player(scene_t *scene, game_manager_t *manager)
{
    void (*player_anim[5])(scene_t *, game_manager_t *) =
        {&animate_idle_run, &animate_jump, &animate_jump,
            &animate_die, &animate_win};
    (*player_anim[scene->player.info.state])(scene, manager);
    sfSprite_setPosition(scene->player.sprite,
            scene->player.info.pos);
    DRAW_SPRITE(manager->window, scene->player.sprite);
}
