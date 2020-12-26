/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** map_setter
*/

#include <my_runner/scene.h>
#include <my_runner/free.h>

bool prepare_map_positions(scene_t *scene, char *file, game_manager_t *manager)
{
    if (scene->enemy)
        destroy_enemy_array(scene);
    if (!map_loader(scene, file, manager)) {
        scene->enemy = NULL;
        return (false);
    }
    sfVector2f pos = VECF(WIN_W + 100, 0);
    for (size_t i = 0; scene->enemy[i].enemy_id != -2; i++) {
        pos.x += 200;
        if (scene->enemy[i].enemy_id == -1)
            continue;
        scene->enemy[i].info.pos.x = pos.x;
        sfSprite_setPosition(scene->enemy[i].sprite,
                scene->enemy[i].info.pos);
    }
    return (true);
}

static void malloc_infinite_array(scene_t *scene)
{
    static bool hash_been_already_malloced = false;

    if (hash_been_already_malloced)
        return;
    hash_been_already_malloced = true;
    scene->enemy = my_calloc(sizeof(enemy_t), INF_ARR_ENEMY_SIZE + 1);
    for (size_t i = 0; i < INF_ARR_ENEMY_SIZE; i++)
        scene->enemy[i].sprite = sfSprite_create();
    scene->enemy[INF_ARR_ENEMY_SIZE] = get_empty_enemy(-2);
}

static void set_positions_sprites(scene_t *scene, size_t i, float *pos,
    game_manager_t *manager)
{
    int minimum_between_ids[4] = {200, 400, 200, 200};
    int id;
    void (*ptr_getter[4])(enemy_t **, int, size_t, game_manager_t *) =
        {&get_phantom, &get_ninja, &get_mushroom, &get_slime};
    sfVector2f scales[4] = {VECF(2, 2), VECF(2.75f, 2.75f),
        VECF(3, 3), VECF(3, 3)};

    srand(rand() % 1000);
    id = rand() % 4;
    (*ptr_getter[id])(&scene->enemy, id, i, manager);
    SET_TEXTURE(scene->enemy[i].sprite, scene->enemy_texture[id]);
    sfSprite_setScale(scene->enemy[i].sprite, scales[id]);
    scene->enemy[i].info.pos.x = *pos;
    sfSprite_setPosition(scene->enemy[i].sprite,
        scene->enemy[i].info.pos);
    *pos += rand() % 500 + minimum_between_ids[id];
}

void prepare_infinity_position(scene_t *scene, game_manager_t *manager)
{
    float pos = WIN_W + 100;

    srand(time(NULL));
    malloc_infinite_array(scene);
    for (size_t i = 0; i < INF_ARR_ENEMY_SIZE; i++) {
        if (rand() % 8 == 0) {
            scene->enemy[i].enemy_id = -1;
            continue;
        }
        set_positions_sprites(scene, i, &pos, manager);
    }
}