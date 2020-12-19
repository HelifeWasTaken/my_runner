/*
** EPITECH PROJECT, 2020
** fake_waiter.c
** File description:
** seems_like_real
*/

#include <my_csfml.h>

static void fake_wait(float sec)
{
    sfClock *clock = sfClock_create();
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asSeconds(time);

    while (seconds < sec) {
        time = sfClock_getElapsedTime(clock);
        seconds = sfTime_asSeconds(time);
    }
    sfClock_destroy(clock);
}

void fake_wait_message(char *message)
{
    my_printf("%s", message);
    fake_wait(0);
    my_putchar('\r');
    for (size_t i = 0; message[i]; i++)
        my_putchar(' ');
    my_putchar('\r');
}