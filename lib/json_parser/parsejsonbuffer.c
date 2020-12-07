/*
** EPITECH PROJECT, 2020
** parse_buffer.c
** File description:
** lodeus_lib
*/

void parsejsonbuffer(char **buffer)
{
    while ((**buffer == ' ' || **buffer == ':' || **buffer == '\n') && **buffer)
        (*buffer)++;
}
