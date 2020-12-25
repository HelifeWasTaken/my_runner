/*
** EPITECH PROJECT, 2020
** draw_score.c
** File description:
** draw_score
*/

#include <my_runner/scene.h>
#include <my_runner/runner.h>

char *concat_string(char *s1, char *s2)
{
    size_t size = my_strlen(s1) + my_strlen(s2);
    char *buffer = malloc(sizeof(char) * (size + 1));

    buffer = my_strcpy(buffer, s1);
    buffer = my_strcat(buffer, s2);
    buffer[size] = '\0';
    return (buffer);
}

void display_info(sfText *text, sfRenderWindow *window,
    char *s1, char *s2)
{
    char *buffer = concat_string(s1, s2);

    sfText_setString(text, buffer);
    free(s1);
    free(s2);
    free(buffer);
    sfRenderWindow_drawText(window, text, NULL);
}
