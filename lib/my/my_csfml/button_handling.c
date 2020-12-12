/*
** EPITECH PROJECT, 2020
** button_handling
** File description:
** handle_buttons
*/

#include <SFML/Graphics.h>

sfBool check_button_click(sfFloatRect button_pos, sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPosition(window);

    return (sfFloatRect_contains(&button_pos, mouse_pos.x, mouse_pos.y));
}