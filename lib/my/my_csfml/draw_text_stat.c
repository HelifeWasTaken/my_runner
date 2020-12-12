/*
** EPITECH PROJECT, 2020
** draw_text_with_a_stat
** File description:
** draw_text
*/

#include <my_csfml.h>

void draw_text_stat(sfRenderWindow *window, text_print_stat_t text_print)
{
    char *nb_str = my_calloc(sizeof(char), get_nb_size(text_print.nb, 10) + 1);

    my_itoa(text_print.nb, nb_str, "0123456789");
    nb_str = my_str_realocat(my_strdup(text_print.str), nb_str);
    sfText_setString(text_print.text, nb_str);
    sfText_setPosition(text_print.text, text_print.position);
    sfRenderWindow_drawText(window, text_print.text, NULL);
    free(nb_str);
}