/*
** EPITECH PROJECT, 2020
** getjsoninfo.c
** File description:
** lodeus_lib
*/

#include <lodeus/json_parser/json.h>

void getjsoninfo(char **buffer, json_t **config)
{
    json_t *config_ptr = *config;

    for (; config_ptr && config_ptr->next; config_ptr = config_ptr->next);
    if (config_ptr == NULL) {
        *config = createjsonnode(buffer);
        return;
    }
    config_ptr->next = createjsonnode(buffer);
}
