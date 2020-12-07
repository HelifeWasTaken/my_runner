/*
** EPITECH PROJECT, 2020
** parsejsonfile.c
** File description:
** lodeus_lib
*/

#include <lodeus/json_parser/json.h>

json_t *parsejsonfile(char **buffer)
{
    json_t *config = NULL;

    while (**buffer) {
        if (**buffer == '"')
            getjsoninfo(buffer, &config);
        else if (**buffer == '}') {
            (*buffer)++;
            return (config);
        }
        else
            (*buffer)++;
    }
    return (config);
}
