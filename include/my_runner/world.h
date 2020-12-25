/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** background
*/

#pragma once

#ifndef __MY__RUNNER__WORLD__H__
    #define __MY__RUNNER__WORLD__H__
    #include <my_csfml.h>
    #include <my_runner/scene.h>
    #include <my_runner/runner.h>

    ////////////////////////////// CONSTRUCTOR ///////////////////////////////

    typedef struct parralax {
        sfSprite *layer;
        sfTexture *texture;
    } parralax_t;

    typedef struct game_background {
        sfSprite *layer;
        sfTexture *texture;
    } background_t;

    #define FOR_EACH_PARRALAX(index, size) \
        for (u_int8_t index = 0; index < size; index++)

    //////////////////////////////// SCENES ///.//////////////////////////////

    enum {
        VOLCANO,
        FOREST,
        SNOW,
    };

    typedef struct {
        parralax_t *para;
        background_t *bg;
        frame_t frame;
    } volcano_world_t;

    typedef struct {
        parralax_t *para;
    } forest_world_t;

    typedef struct {
        parralax_t *para;
    } snow_world_t;

    typedef struct world {
        volcano_world_t volcano;
        forest_world_t forest;
        snow_world_t snow;
        int8_t choice;
    } world_t;

    ////////////////////////////// VOLCANO ///////////////////////////////

    #define NB_PARA_VOLCANO         8
    #define PARA_VOLCANO_ONE        "asset/png/night/volcano/layer01.png"
    #define PARA_VOLCANO_TWO        "asset/png/night/volcano/layer02.png"
    #define PARA_VOLCANO_THREE      "asset/png/night/volcano/layer03.png"
    #define PARA_VOLCANO_FOUR       "asset/png/night/volcano/layer04.png"
    #define PARA_VOLCANO_FIVE       "asset/png/night/volcano/layer05.png"
    #define PARA_VOLCANO_SIX        "asset/png/night/volcano/layer06.png"
    #define PARA_VOLCANO_SEVEN      "asset/png/night/volcano/layer07.png"
    #define PARA_VOLCANO_HEIGHT     "asset/png/night/volcano/layer08.png"

    #define NB_BG_VOLCANO           3
    #define BG_VOLCANO_ONE          "asset/png/night/volcano/anim01.png"
    #define BG_VOLCANO_TWO          "asset/png/night/volcano/anim02.png"
    #define BG_VOLCANO_THREE        "asset/png/night/volcano/anim03.png"

    ////////////////////////////// FOREST ///////////////////////////////

    #define NB_PARA_FOREST          6
    #define PARA_FOREST_ONE         "asset/png/night/myst_forest/layer01.png"
    #define PARA_FOREST_TWO         "asset/png/night/myst_forest/layer02.png"
    #define PARA_FOREST_THREE       "asset/png/night/myst_forest/layer03.png"
    #define PARA_FOREST_FOUR        "asset/png/night/myst_forest/layer04.png"
    #define PARA_FOREST_FIVE        "asset/png/night/myst_forest/layer05.png"
    #define PARA_FOREST_SIX         "asset/png/night/myst_forest/layer06.png"

    ////////////////////////////// FOREST ///////////////////////////////

    #define NB_PARA_SNOW            9
    #define PARA_SNOW_ONE           "asset/png/day/snow/layer01.png"
    #define PARA_SNOW_TWO           "asset/png/day/snow/layer02.png"
    #define PARA_SNOW_THREE         "asset/png/day/snow/layer03.png"
    #define PARA_SNOW_FOUR          "asset/png/day/snow/layer04.png"
    #define PARA_SNOW_FIVE          "asset/png/day/snow/layer05.png"
    #define PARA_SNOW_SIX           "asset/png/day/snow/layer06.png"
    #define PARA_SNOW_SEVEN         "asset/png/day/snow/layer07.png"
    #define PARA_SNOW_HEIGHT        "asset/png/day/snow/layer08.png"
    #define PARA_SNOW_NINE          "asset/png/day/snow/layer09.png"

    #define NB_WORLD        3
#endif