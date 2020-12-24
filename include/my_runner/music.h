/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** music
*/

#pragma once

#ifndef __RUNNER__MUSIC__H__
    #define __RUNNER__MUSIC__H__
    #include <SFML/Audio.h>

    typedef struct {
        sfSoundBuffer *buffer;
        sfSound *sound;
    } sound_info_t;

    typedef struct {
        sound_info_t player_jump;
        sound_info_t player_land;
        sound_info_t player_death;
        sfMusic *game;
    } music_t;

    #define PLAYER_SOUND_JUMP   "./asset/sound/used/jump.wav"
    #define PLAYER_SOUND_LAND   "./asset/sound/used/land.wav"
    #define PLAYER_DEATH_SOUND  "./asset/sound/used/death.ogg"
    #define GLOBAL_GAME_SOUND   "./asset/sound/used/game4.ogg"
#endif