/*
** EPITECH PROJECT, 2020
** create_static_image
** File description:
** create_an_image_easily
*/

#include <SFML/Graphics.h>

sfSprite *create_static_image(char const *filename)
{
    sfTexture *texture = sfTexture_createFromFile(filename, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfFalse);
    return (sprite);
}