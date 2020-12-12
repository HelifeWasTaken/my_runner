/*
** EPITECH PROJECT, 2020
** wait_before_launching_game
** File description:
** wait
*/

#include <SFML/Audio.h>
#include <my_hunter.h>

void mini_loading(sfMusic *sound, float time_to_wait, sfBool has_music,
    general_t *general)
{
    sfClock *waiting_clock = sfClock_create();
    sfTime get_waited_time = sfClock_getElapsedTime(waiting_clock);
    float seconds = 0;

    if (has_music)
        sfMusic_play(sound);
    while (seconds < time_to_wait) {
        get_waited_time = sfClock_getElapsedTime(waiting_clock);
        seconds = sfTime_asSeconds(get_waited_time);
        general->mouse_pos = sfMouse_getPositionRenderWindow(general->window);
        draw_all_game(general);
    }
    sfClock_destroy(waiting_clock);
    if (has_music)
        sfMusic_stop(sound);
}