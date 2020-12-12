/*
** EPITECH PROJECT, 2020
** printjson.c
** File description:
** lodeus_lib
*/

#include <lodeus/json_parser/json.h>
#include <lodeus/stdio.h>

void printjsonint(json_t *config)
{
    lprintf("%lld\n", (jsonint_t)config->key_value);
}

void printjsonstr(json_t *config)
{
    lprintf("\"%s\"\n", (jsonstr_t)config->key_value);
}

void printjsonbool(json_t *config)
{
    ((jsonint_t)config->key_value) ? lprintf("true") : lprintf("false");
}

void printjsonnull(json_t *config __attribute__((unused)))
{
    lprintf("null");
}
