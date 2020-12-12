/*
** EPITECH PROJECT, 2020
** getjsonkeyname.c
** File description:
** lodeus_lib
*/

#include <lodeus/json_parser/json.h>

keyname_t getjsonkeyname(char **buffer)
{
    size_t i = 0;
    keyname_t keyname = NULL;

    if (**buffer != '"')
        parsejsonbuffer(buffer);
    if (**buffer == '"')
        (*buffer)++;
    for (; (*buffer)[i] && (*buffer)[i] != '"'; i++);
    keyname = lstrndup(*buffer, i);
    *buffer += i + 1;
    return (keyname);
}
