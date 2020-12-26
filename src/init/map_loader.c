/*
** EPITECH PROJECT, 2020
** map_loader.c
** File description:
** map_loader
*/

#include <my_runner/scene.h>
#include <my_runner/free.h>
#include <my_str.h>
#include <stdio.h>

static ssize_t get_enemy_type(char enemy)
{
    char known_enemy[5] = "fnms";
    u_int8_t enemy_id[NB_ENEMY] = {FLY_ENEMY, NINJA, MUSHROOM, SLIME};

    if (!enemy)
        return (-2);
    for (size_t i = 0; known_enemy[i]; i++) {
        if (known_enemy[i] == enemy)
            return (enemy_id[i]);
    }
    return (-2);
}

static void fill_enemy_info(enemy_t **new, scene_t *scene, int enemy_id,
        size_t i)
{
    void (*getter_ptr[4])(enemy_t **new, int enemy_id, size_t i) =
    {0, &get_ninja, &get_mushroom, &get_slime};

    (*getter_ptr[enemy_id])(new, enemy_id, i);
    (*new)[i].sprite = sfSprite_create();
    SET_TEXTURE((*new)[i].sprite, scene->enemy_texture[enemy_id]);
    if ((*new)[i].enemy_id != NINJA)
        sfSprite_setScale((*new)[i].sprite, VECF(3, 3));
    else
        sfSprite_setScale((*new)[i].sprite, VECF(2.75, 2.75));
}

static bool set_enemy_in_array(scene_t *scene, char *buff)
{
    size_t i;
    int enemy_id = 0;

    scene->enemy = my_calloc(sizeof(enemy_t), (my_strlen(buff) + 1));
    for (i = 0; buff[i] && buff[i] != '\n'; i++) {
        if (buff[i] == '.') {
            scene->enemy[i] = get_empty_enemy(-1);
            continue;
        }
        enemy_id = get_enemy_type(buff[i]);
        if (enemy_id == -2) {
            scene->enemy[i] = get_empty_enemy(-2);
            SHOW_ERROR_LOG_UNSUPORTED_CHAR
            return (false);
        }
        fill_enemy_info(&scene->enemy, scene, enemy_id, i);
    }
    scene->enemy[i] = get_empty_enemy(-2);
    return (true);
}

static void free_map(scene_t *scene, char *buffer, FILE *file)
{
    if (scene->enemy)
        destroy_enemy_array(scene);
    if (buffer) {
        buffer = NULL;
        free(buffer);
    }
    if (file)
        fclose(file);
}

bool map_loader(scene_t *scene, char *filepath)
{
    char *buffer = NULL;
    FILE *map_file = fopen(filepath, "r");
    size_t buffer_index = 0;

    if (scene->enemy)
        destroy_enemy_array(scene);
    if (map_file == NULL) {
        free_map(scene, buffer, map_file);
        SHOW_ERROR_LOG_OPEN_FILE_FAIL(filepath);
        return (false);
    }
    if (getline(&buffer, &buffer_index, map_file) == -1 || buffer == NULL ||
            !set_enemy_in_array(scene, buffer)) {
        free_map(scene, buffer, map_file);
        return (false);
    }
    fclose(map_file);
    if (buffer)
        free(buffer);
    return (true);
}
