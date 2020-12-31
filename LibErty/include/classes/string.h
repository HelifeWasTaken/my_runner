/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** string
*/

#ifndef __LIBERTY__CLASS_STRING__H__
    #define __LIBERTY__CLASS_STRING__H__

    #include <estring.h>

    typedef struct {
        char *str;
        size_t s_size;
        size_t a_size;
    } string_t;

    string_t *empty_string(void);
    string_t *empty_alloced_string(size_t size);
    string_t *new_string(char const *buff);
    string_t *replace_string(string_t *self, char const *buff);
    string_t *overwrite_string(string_t *self, char const *buff);
    string_t *insert_string(char const *buff);
    string_t *insert_char(char const *buff);
    string_t *erase_in_string(string_t *self, size_t start, size_t end);
    string_t *resize_string(string_t *self, size_t count);
    char *string_to_buff(string_t *self);
    void free_string(string_t *string);

#endif /* !__LIBERTY__CLASS_STRING__H__ */
