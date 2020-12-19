/*
** EPITECH PROJECT, 2020
** my_st_size.c
** File description:
** lodeus_lib
*/

#include <my_csfml.h>
#include <fcntl.h>
#include <unistd.h>

static char *getoneline_str(char *dest, char *src, ssize_t ret_read)
{
    size_t size_dest = my_strlen(dest);
    char *new_str = NULL;

    if (!dest) {
        new_str = my_strdup(src);
        new_str[ret_read] = '\0';
        my_memset(src, 0, ret_read);
        return (new_str);
    }
    new_str = malloc(sizeof(char) * (size_dest + ret_read + 1));
    my_strcpy(new_str, dest);
    my_strncat(new_str, src, ret_read);
    free(dest);
    my_memset(src, 0, ret_read);
    new_str[size_dest + ret_read] = '\0';
    return (new_str);
}

char *getoneline(char *pathfile)
{
    int file_fd = open(pathfile, O_RDONLY);
    ssize_t ret_read;
    char *line = NULL;
    char buffer[100] = {0};

    if (file_fd == -1) {
        close(file_fd);
        return (NULL);
    }
    while ((ret_read = read(file_fd, buffer, 99)) > 0)
        line = getoneline_str(line, buffer, ret_read);
    close(file_fd);
    return (line);
}
