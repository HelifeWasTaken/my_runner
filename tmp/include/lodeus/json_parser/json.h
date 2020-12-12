/*
** EPITECH PROJECT, 2020
** mini_parser.h
** File description:
** lodeus_lib
*/

#ifndef __LODEUS__MINI__PARSER__H__
#define __LODEUS__MINI__PARSER__H__
#define _GNU_SOURCE
#include <lodeus/string.h>
#include <stdlib.h>
#include <lodeus/ctypes.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
typedef void * keyvalue_t;
typedef char * keyname_t;
typedef uint8_t keytype_t;
typedef struct stat statfile_t;
typedef int fd_t;
typedef char * jsonstr_t;
typedef long long jsonint_t;
typedef bool jsonbool_t;
typedef void * jsonnull_t;

enum {
    JSON_INT,
    JSON_STR,
    JSON_BOOL,
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_NULL
};
typedef struct json_file {
    keyname_t key;
    keytype_t type;
    keyvalue_t key_value;
    struct json_file *datain;
    struct json_file *next;
    struct json_file *array;
} json_t;
json_t *jsonparser(char *filepath);
void free_jsonconfig(json_t **config);
char *getoneline(char *pathfile);
void printjson(json_t *config);
json_t *parsejsonfile(char **buffer);
void *seekinfo(json_t *config, keyname_t key);
json_t *gotoinfo(json_t *config, keyname_t key);
void printjsonnull(json_t *config __attribute__((unused)));
void printjsonbool(json_t *config);
void printjsonstr(json_t *config);
void printjsonint(json_t *config);
void getjsoninfo(char **buffer, json_t **config);
json_t *createjsonnode(char **buffer);
json_t *getjsonkeyvalue(char **buffer, json_t *config);
keyname_t getjsonkeyname(char **buffer);
void parsejsonbuffer(char **buffer);
#ifdef __KEY_VALUE_NON_STATIC__
json_t *getbooleankeyvalue(char **buffer, json_t *config);
json_t *getstringkeyvalue(char **buffer, json_t *config);
json_t *getnumkeyvalue(char **buffer, json_t *config);
#endif
#define SEEK_INT(c, p) (jsonint_t)seekinfo(c, p)
#define SEEK_BOOL(c, p) (jsonint_t)seekinfo(c, p)
#define SEEK_STR(c, p) (jsonstr_t)seekinfo(c, p)
#endif
