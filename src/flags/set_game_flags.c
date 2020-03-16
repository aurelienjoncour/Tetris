/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** key arrows
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "my.h"
#include "tetris.h"

int put_help(__attribute((unused))char *arg,
            __attribute((unused))flags_t *flags)
{
    struct stat st;
    char *buffer;
    int fd;
    int read_size;

    if (stat(USAGE_FILEPATH, &st) == -1)
        return EXIT_ERROR;
    fd = open(USAGE_FILEPATH, O_RDONLY);
    buffer = malloc(sizeof(char) * st.st_size + 1);
    if (fd == -1 || buffer == NULL)
        return EXIT_ERROR;
    read_size = read(fd, buffer, st.st_size);
    close(fd);
    if (read_size == -1)
        return EXIT_ERROR;
    buffer[read_size] = '\0';
    my_putstr(buffer);
    free(buffer);
    return EXIT_SUCCESS;
}

static void delete_index(char *str, int i)
{
    for (; str[i] != '\0'; i++)
        str[i] = str[i + 1];
}

int set_level(char *arg, flags_t *flags)
{
    for (int i = 0; arg[i] != '\0'; i++)
        if (arg[i] < '0' || arg[i] > '9')
            delete_index(arg, i--);
    flags->level = my_getnbr(arg);
    return EXIT_SUCCESS;
}

int toggle_next(__attribute((unused))char *arg, flags_t *flags)
{
    flags->without_next = !flags->without_next;
    return EXIT_SUCCESS;
}

int toggle_debug(__attribute((unused))char *arg, flags_t *flags)
{
    flags->debug = !flags->debug;
    return EXIT_SUCCESS;
}