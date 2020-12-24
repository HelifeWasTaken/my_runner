/*
** EPITECH PROJECT, 2020
** draw_score.c
** File description:
** draw_score
*/

#include <my_runner/scene.h>
#include <my_runner/runner.h>

static char *concat_string(char *s1, char *s2)
{
    size_t size = my_strlen(s1) + my_strlen(s2);
    char *buffer = malloc(sizeof(char) * (size + 1));

    buffer = my_strcpy(buffer, s1);
    buffer = my_strcat(buffer, s2);
    buffer[size] = '\0';
    return (buffer);
}

void display_score(scene_t *scene, game_manager_t *manager)
{
    char *num = my_itoa(manager->score, "0123456789");
    char *buffer = concat_string("score: ", num);

    sfText_setString(scene->text.text_score, buffer);
    free(num);
    free(buffer);
    sfRenderWindow_drawText(manager->window, scene->text.text_score, NULL);
}
