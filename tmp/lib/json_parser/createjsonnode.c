/*
** EPITECH PROJECT, 2020
** createjsonnode.c
** File description:
** lodeus_lib
*/

#include <lodeus/json_parser/json.h>

json_t *createjsonnode(char **buffer)
{
    json_t *tmp = NULL;

    while ((**buffer == ' ' || **buffer == '\n') && **buffer && **buffer != '}')
        (*buffer)++;
    if (**buffer == '}' || **buffer == '\0')
        return (tmp);
    tmp = malloc(sizeof(json_t));
    tmp->key = getjsonkeyname(buffer);
    tmp->next = NULL;
    tmp->datain = NULL;
    parsejsonbuffer(buffer);
    if (**buffer == '{') {
        (*buffer)++;
        tmp->datain = parsejsonfile(buffer);
        tmp->type = JSON_OBJECT;
        tmp->key_value = "Object";
    } else
        tmp = getjsonkeyvalue(buffer, tmp);
    return (tmp);
}
