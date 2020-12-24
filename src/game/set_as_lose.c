/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** set_as_lose
*/

#include <my_runner/scene.h>

void set_game_as_lose(scene_t *scene)
{
    sfSound_play(scene->music.player_death.sound);
    sfMusic_stop(scene->music.game);
    scene->player.info.state = DYING;
    scene->player.frame.frame = 0;
}