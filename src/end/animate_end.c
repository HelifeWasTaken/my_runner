/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** animate_end
*/

#include <my_runner/runner.h>
#include <my_runner/scene.h>

static void draw_rest_animation(scene_t *scene, game_manager_t *manager,
        const sfIntRect *rects)
{
    display_score(scene, manager);
    DRAW_SPRITE(manager->window, scene->menu.sprite_b2);
    animate_sprite(rects, scene->player.sprite,
            &scene->player.frame, manager->clock);
    DRAW_SPRITE(manager->window, scene->player.sprite);
    DISPLAY_WINDOW(manager->window);
}

void animate_end(scene_t *scene, game_manager_t *manager)
{
    const sfIntRect player_idle_frames[6] = {
        IRECT(1, 18, 12, 14), IRECT(16, 17, 13, 13), IRECT(32, 17, 13, 15),
        IRECT(49, 17, 12, 15), IRECT(65, 17, 12, 13), IRECT(81, 18, 12, 14)};
    sfVector2f pos_score = sfText_getPosition(scene->text.text_score);
    sfVector2f pos_player = sfSprite_getPosition(scene->player.sprite);
    sfVector2f pos_button = sfSprite_getPosition(scene->menu.sprite_b2);

    CLEAR_WINDOW(manager->window);
    DRAW_SPRITE(manager->window, scene->end.sprite_bg);
    if (pos_score.y > WIN_H / 2 + 50) {
        sfText_setPosition(scene->text.text_score,
                VECF(pos_score.x, pos_score.y - 5));
        sfSprite_setPosition(scene->player.sprite,
                VECF(pos_player.x, pos_player.y - 5));
        sfSprite_setPosition(scene->menu.sprite_b2,
                VECF(pos_button.x, pos_button.y - 5));
    }
    draw_rest_animation(scene, manager, player_idle_frames);
}