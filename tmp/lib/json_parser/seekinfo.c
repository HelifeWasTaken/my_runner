/*
** EPITECH PROJECT, 2020
** seekinfo.c
** File description:
** lodeus_lib
*/

#include <lodeus/json_parser/json.h>

void *seekinfo(json_t *config, keyname_t key)
{
    char **keyarray = lsplit(key, '.');
    size_t i = 0;

    while (config) {
        if (lstrcmp(keyarray[i], config->key) == 0) {
            if (config->type == JSON_OBJECT) {
                config = config->datain;
                i++;
                continue;
            }
            else {
                freelsplit(keyarray);
                return (config->key_value);
            }
        }
        config = config->next;
    }
    freelsplit(keyarray);
    return (NULL);
}

json_t *gotoinfo(json_t *config, keyname_t key)
{
    char **keyarray = lsplit(key, '.');
    size_t i = 0;

    while (config) {
        if (lstrcmp(keyarray[i], config->key) == 0) {
            if (config->type == JSON_OBJECT && keyarray[i + 1]) {
                config = config->datain;
                i++;
                continue;
            } else {
                freelsplit(keyarray);
                return (config);
            }
        }
        config = config->next;
    }
    freelsplit(keyarray);
    return (NULL);
}