/*
** EPITECH PROJECT, 2020
** read_entiere_fill
** File description:
** read_entiere_file
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "tetris.h"

static off_t get_filesize(const char *filepath)
{
    struct stat st;

    stat(filepath, &st);
    return st.st_size;
}

char *get_buffer_map(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    off_t file_size = get_filesize(filepath);
    char *buffer = fd != -1 ? malloc(sizeof(char) * (file_size + 1)) : NULL;
    int size;

    if (buffer == NULL)
        return NULL;
    size = read(fd, buffer, file_size);
    close(fd);
    if (size <= 0) {
        free(buffer);
        return NULL;
    }
    buffer[size] = '\0';
    return buffer;
}

char **read_entiere_file(const char *filepath)
{
    char *map = get_buffer_map(filepath);
    char **array;

    if (map == NULL)
        return NULL;
    array = my_str_to_array(map, "\n", false);
    free(map);
    return array;
}

int put_file(char const *binary)
{
    char *buffer = get_buffer_map(USAGE_FILEPATH);

    if (buffer == NULL)
        return EXIT_ERROR;
    my_putstr("Usage:\t");
    my_putstr(binary);
    my_putstr(" [options]\n");
    my_putstr(buffer);
    free(buffer);
    return EXIT_SUCCESS;
}