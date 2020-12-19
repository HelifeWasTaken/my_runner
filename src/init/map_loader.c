/*
** EPITECH PROJECT, 2020
** map_loader.c
** File description:
** map_loader
*/

#include <my_runner/scene.h>
#include <my_str.h>
#include <stdio.h>

static ssize_t get_enemy_type(char enemy)
{
    char known_enemy[5] = "fgms";
    u_int8_t enemy_id[NB_ENEMY * 2] = {FLY_ENEMY, GOBLIN, MUSHROOM, SLIME};

    if (!enemy)
        return (-1);
    for (size_t i = 0; known_enemy[i]; i++) {
        if (known_enemy[i] == enemy)
            return (enemy_id[i]);
    }
    return (-1);
}

static void fill_enemy_info(map_t **new, scene_t *scene, int enemy_id, size_t i)
{
    sfVector2f momentum_enemy[4] = {VECF(0, 0), VECF(0, 0), VECF(0, 0),
        VECF(-0.5f, 0.5f)};
    float max_vel_enemy[4] = {0, 0, 0, 4};
    float max_h_enemy[4] = {0, 0, 0, GROUND_HEIGHT_SLIME - 60};
    float min_h_enemy[4] = {0, 0, GROUND_HEIGHT_MUSHROOM, GROUND_HEIGHT_SLIME};
    (*new)->enemy[i].sprite = sfSprite_create();
    (*new)->enemy[i].frame = (frame_t){0, 0};
    (*new)->enemy[i].enemy_id = enemy_id;
    (*new)->enemy[i].state = IDLE;
    (*new)->enemy[i].info = (gravity_t){momentum_enemy[enemy_id],
        max_vel_enemy[enemy_id], VECF(0, 0), min_h_enemy[enemy_id],
        max_h_enemy[enemy_id], VECF(WIN_W + 200, 0), ON_GROUND};
    SET_TEXTURE((*new)->enemy[i].sprite, scene->enemy_texture[enemy_id]);
    sfSprite_setScale((*new)->enemy[i].sprite, VECF(3, 3));
}

static bool set_enemy_in_array(scene_t *scene, char *buffer)
{
    size_t i;
    int enemy_id = 0;

    scene->map = malloc(sizeof(map_t));
    scene->map->enemy = malloc(sizeof(enemy_t) * (my_strlen(buffer) + 1));
    for (i = 0; buffer[i] && buffer[i] != '\n'; i++) {
        if (buffer[i] == '.') {
            scene->map->enemy[i] = (enemy_t){(frame_t){0}, NULL,
                -1, IDLE, (gravity_t){0}};
            continue;
        }
        enemy_id = get_enemy_type(buffer[i]);
        if (enemy_id == -1) {
            return (false);
        }
        fill_enemy_info(&scene->map, scene, enemy_id, i);
    }
    scene->map->enemy[i].enemy_id = -2;
    return (true);
}

bool map_loader(scene_t *scene, char *filepath)
{
    char *buffer = NULL;
    FILE *map_file = fopen(filepath, "r");
    size_t buffer_index = 0;

    if (map_file == NULL) {
        my_dprintf(2,
                   RED "my_runner: " YELLOW "Could not open file !\n" DEFAULT);
        return (false);
    }
    getline(&buffer, &buffer_index, map_file);
    if (buffer == NULL)
        return (false);
    if (!set_enemy_in_array(scene, buffer))
        return (false);
    return (true);
}
