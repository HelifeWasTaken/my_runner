/*
** EPITECH PROJECT, 2020
** my_runner.h
** File description:
** runner
*/

#ifndef __MY_RUNNER__H__
#define __MY_RUNNER__H__
#include <my_csfml.h>

enum {
    GAME,
    MENU
};

enum {
    BACKGROUND_FRAME_ONE,
    BACKGROUND_FRAME_TWO,
    BACKGROUND_FRAME_THREE
};

enum {
    PLAYER_FRAME_ONE,
    PLAYER_FRAME_TWO,
    PLAYER_FRAME_THREE,
    PLAYER_FRAME_FOUE,
    PLAYER_FRAME_FIVE,
    PLAYER_FRAME_SIX,
    PLAYER_FRAME_SEVEN,
    PLAYER_FRAME_HEIGHT
};

typedef struct parralax {
    sfSprite *layer;
    sfTexture *texture;
} parralax_t;

typedef struct game_bacground {
    sfSprite *layer;
    sfTexture *texture;
} g_background_t;

typedef struct scene_animation_time {
    float parralax;
} time_anim_t;

typedef struct player {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
} player_t;

typedef struct frame_manager {
    u_int8_t frame;
    float elapsed_time;
} frame_t;

typedef struct scene {
    parralax_t *parralax;
    g_background_t *background;
    player_t player;
    frame_t player_frame;
    frame_t background_frame;
} scene_t;


typedef struct game_manager {
    sfRenderWindow *window;
    sfClock *clock;
    sfEvent event;
} game_manager_t;

#define WINDOW_NAME "my_runner"
#define WINDOW_SIZE (sfVideoMode){1536, 768, 32}
#define PLAYER_SPRITE "asset/png/characters/01.png"
#define TIME_SHIFT_PLAYER 0.1f
#define NB_PARRALAX 8
#define NB_BACKGROUND 3
#define BACKGROUND_LAYER_ONE "asset/png/night/volcano/anim01.png"
#define BACKGROUND_LAYER_TWO "asset/png/night/volcano/anim02.png"
#define BACKGROUND_LAYER_THREE "asset/png/night/volcano/anim03.png"
#define TIME_SHIFT_BACKGROUND 0.18f
#define PARRALAX_LAYER_ONE "asset/png/night/volcano/layer01.png"
#define PARRALAX_LAYER_TWO "asset/png/night/volcano/layer02.png"
#define PARRALAX_LAYER_THREE "asset/png/night/volcano/layer03.png"
#define PARRALAX_LAYER_FOUR "asset/png/night/volcano/layer04.png"
#define PARRALAX_LAYER_FIVE "asset/png/night/volcano/layer05.png"
#define PARRALAX_LAYER_SIX "asset/png/night/volcano/layer06.png"
#define PARRALAX_LAYER_SEVEN "asset/png/night/volcano/layer07.png"
#define PARRALAX_LAYER_HEIGHT "asset/png/night/volcano/layer08.png"
#define GROUND_HEIGHT 652
#define FOR_EACH_PARRALAX(index) \
    for (u_int8_t index = 0; index < NB_PARRALAX; index++)

scene_t init_scene(void);
void draw_parralax(scene_t *scene, game_manager_t *manager);
void draw_background(scene_t *scene, game_manager_t *manager);
void draw_player(scene_t *scene, game_manager_t *manager);
void draw_all_game(scene_t *scene, game_manager_t *manager);
#endif
