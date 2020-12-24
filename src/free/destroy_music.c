/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** destroy_music
*/

#include <my_runner/free.h>

void destroy_music(scene_t *scene)
{
    if (scene->music.player_jump.buffer)
        sfSoundBuffer_destroy(scene->music.player_jump.buffer);
    if (scene->music.player_jump.sound)
        sfSound_destroy(scene->music.player_jump.sound);
    if (scene->music.player_land.buffer)
        sfSoundBuffer_destroy(scene->music.player_land.buffer);
    if (scene->music.player_land.sound)
        sfSound_destroy(scene->music.player_land.sound);
    if (scene->music.player_death.buffer)
        sfSoundBuffer_destroy(scene->music.player_death.buffer);
    if (scene->music.player_death.sound)
        sfSound_destroy(scene->music.player_death.sound);
    if (scene->music.game)
        sfMusic_destroy(scene->music.game);
}