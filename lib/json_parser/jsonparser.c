/*
** EPITECH PROJECT, 2020
** mini_parser.c
** File description:
** lodeus_lib
*/

#include <lodeus/json_parser/json.h>

json_t *jsonparser(char *filepath)
{
    char *buffer = getoneline(filepath);
    char *buffer_ptr = buffer;
    json_t *conf = parsejsonfile(&buffer);

    free(buffer_ptr);
    return (conf);
}
