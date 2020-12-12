/*
** EPITECH PROJECT, 2020
** check_if_mouse_is_over
** File description:
** check
*/

#include <SFML/Graphics.h>

sfBool check_if_mouse_over_sprite(sfSprite *sprite, sfVector2i mouse_pos)
{
    sfFloatRect sprite_pos = sfSprite_getGlobalBounds(sprite);
    return (sfFloatRect_contains(&sprite_pos, mouse_pos.x, mouse_pos.y));
}