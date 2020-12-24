/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** load_music
*/

#include <my_runner/scene.h>

bool load_music(scene_t *scene)
{
    scene->music.player_jump.sound = sfSound_create();
    scene->music.player_jump.buffer = CREATE_SOUND_BUFFER(PLAYER_SOUND_JUMP);
    scene->music.player_land.sound = sfSound_create();
    scene->music.player_land.buffer = CREATE_SOUND_BUFFER(PLAYER_SOUND_LAND);
    scene->music.game = sfMusic_createFromFile(GLOBAL_GAME_SOUND);
    scene->music.player_death.sound = sfSound_create();
    scene->music.player_death.buffer = CREATE_SOUND_BUFFER(PLAYER_DEATH_SOUND);
    if (!scene->music.player_jump.buffer || !scene->music.player_death.buffer ||
            !scene->music.game || !scene->music.player_land.buffer)
        return (false);
    sfSound_setBuffer(scene->music.player_death.sound,
            scene->music.player_death.buffer);
    sfSound_setBuffer(scene->music.player_jump.sound,
            scene->music.player_jump.buffer);
    sfSound_setBuffer(scene->music.player_land.sound,
            scene->music.player_land.buffer);
    return (true);
}
