/*
** EPITECH PROJECT, 2020
** my_st_size.c
** File description:
** lodeus_lib
*/

#include <lodeus/json_parser/json.h>

static char *getoneline_str(char *dest, char *src, ssize_t ret_read)
{
    size_t size_dest = lstrlen(dest);
    char *new_str = NULL;

    if (!dest) {
        new_str = lstrdup(src);
        new_str[ret_read] = '\0';
        lmemset(src, 0, ret_read);
        return (new_str);
    }
    new_str = malloc(sizeof(char) * (size_dest + ret_read + 1));
    lstrcpy(new_str, dest);
    lstrncat(new_str, src, ret_read);
    free (dest);
    lmemset(src, 0, ret_read);
    new_str[size_dest + ret_read] = '\0';
    return (new_str);
}

char *getoneline(char *pathfile)
{
    fd_t file_fd = open(pathfile, O_RDONLY);
    ssize_t ret_read;
    char *line = NULL;
    char buffer[100] = {0};

    while ((ret_read = read(file_fd, buffer, 99)) > 0)
        line = getoneline_str(line, buffer, ret_read);
    close(file_fd);
    return (line);
}
