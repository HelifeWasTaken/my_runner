/*
** EPITECH PROJECT, 2020
** getjsonkeyvalue.c
** File description:
** lodeus_lib
*/

#include <lodeus/json_parser/json.h>
#include <lodeus/stdlib.h>

static json_t *getbooleankeyvalue(char **buffer, json_t *config)
{
    if (lstrncmp(*buffer, "true", 4) == 0) {
        config->key_value = (keyvalue_t) true;
        config->type = JSON_BOOL;
        *buffer += 4;
        return (config);
    }
    else {
        config->key_value = (keyvalue_t) false;
        config->type = JSON_BOOL;
        *buffer += 5;
        return (config);
    }
}

static json_t *getstringkeyvalue(char **buffer, json_t *config)
{
    config->key_value = (keyvalue_t)getjsonkeyname(buffer);
    config->type = JSON_STR;
    return (config);
}

static json_t *getnumkeyvalue(char **buffer, json_t *config)
{
    long long nb = latoll(*buffer);

    *buffer += lnblen(nb);
    config->key_value = (keyvalue_t)nb;
    config->type = JSON_INT;
    return (config);
}

json_t *getjsonkeyvalue(char **buffer, json_t *config)
{
    if (**buffer == '"')
        return (getstringkeyvalue(buffer, config));
    if (lisnum(**buffer))
        return (getnumkeyvalue(buffer, config));
    if (lstrncmp(*buffer, "true", 4) == 0 || lstrncmp(*buffer, "false", 5) == 0)
        return (getbooleankeyvalue(buffer, config));
    if (lstrncmp(*buffer, "null", 4) == 0) {
        config->key_value = NULL;
        config->type = JSON_NULL;
        *buffer += 4;
        return (config);
    }
    return (NULL);
}
