/*
** EPITECH PROJECT, 2020
** free_jsonconfig.c
** File description:
** lodeus_lib
*/

#include <lodeus/json_parser/json.h>

void free_jsonconfig(json_t **config)
{
    if (*config) {
        if ((*config)->next)
            free_jsonconfig(&(*config)->next);
        if ((*config)->datain)
            free_jsonconfig(&(*config)->datain);
        if ((*config)->type == JSON_STR) {
            if ((*config)->key_value)
                free((*config)->key_value);
        }
        free((*config)->key);
        free(*config);
    }
}
