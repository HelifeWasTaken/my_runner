/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myrunner-mattis.dalleau
** File description:
** manager_keyboard
*/

#include <my_csfml.h>

static void process_remove_char(char **buf, size_t size_buf)
{
    char *new_buf = NULL;
    size_t i = 0;

    new_buf = malloc(sizeof(char) * (size_buf));
    for (; (*buf)[i + 1]; i++)
        new_buf[i] = (*buf)[i];
    new_buf[i] = 0;
    free(*buf);
    *buf = NULL;
    *buf = new_buf;
}

static void remove_char(char **buf)
{
    size_t size_buf;

    if (*buf == NULL)
        return;
    size_buf = my_strlen(*buf);
    if (size_buf == 1) {
        *buf = NULL;
        return;
    }
    process_remove_char(buf, size_buf);
}

static void add_char(char **buf, char c)
{
    char *new_buf = NULL;
    size_t i = 0;

    if (*buf == NULL) {
        *buf = malloc(2);
        (*buf)[0] = c;
        (*buf)[1] = 0;
        return;
    }
    new_buf = malloc(sizeof(char) * (my_strlen(*buf) + 2));
    for (; (*buf)[i]; i++)
        new_buf[i] = (*buf)[i];
    new_buf[i] = c;
    i++;
    new_buf[i] = 0;
    free(*buf);
    *buf = new_buf;
}

static bool check_if_add(char **buf, int i)
{
    char *alpha = "abcdefghijklmnopqrstuvwxyz0123456789\0\0\0\0\0\0\0\0\0\0\0\0"
        ";,.'/\\~=- \0\0\t\0\0\0~\0\0+-*/\0\0\0\0""0123456789";

    if (alpha[i]) {
        if (sfKeyboard_isKeyPressed(i)) {
            add_char(buf, alpha[i]);
            return (true);
        }
    }
    return (false);
}

char *handle_keyboard(char *buf)
{
    if (sfKeyboard_isKeyPressed(sfKeyDelete) ||
            sfKeyboard_isKeyPressed(sfKeyBackspace)) {
        remove_char(&buf);
        return (buf);
    }
    if (my_strlen(buf) >= 30)
        return (buf);
    for (int i = 0; i < 85; i++) {
        if (check_if_add(&buf, i))
            break;
    }
    return (buf);
}
