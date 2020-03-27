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

static const char *usage[] = {
    "Options:\n",
    " --help \t\tDisplay this help\n",
    " -L --level={num} \tStart Tetris at level num (def: 1)\n",
    " -l --key-left={K} \tMove the tetrimino LEFT using the K key ",
    "(def: left arrow)\n",
    " -r --key-right={K} \tMove the tetrimino RIGHT using the K key",
    " (def: right arrow)\n",
    " -t --key-turn={K} \tTURN the tetrimino clockwise 90d using ",
    "the K key (def: top arrow)\n",
    " -d --key-drop={K} \tDROP the tetrimino using the K key ",
    "(def: down arrow)\n",
    " -q --key-quit={K} \tQUIT the game using the K key (def: ",
    "‘q’ key)\n",
    " -p --key-pause={K} \tPAUSE/RESTART the game using the K key ",
    "(def: space bar)\n",
    " --map-size={row,col} \tSet the numbers of rows and columns ",
    "of the map (def: 20,10)\n",
    " -w --without-next \tHide next tetrimino (def: false)\n",
    " -D --debug \t\tDebug mode (def: false)\n",
    NULL,
};

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
    my_putstr("Usage: ");
    my_putstr(binary);
    my_putstr(" [options]\n");
    for (size_t i = 0; usage[i] != NULL; i++)
        my_putstr(usage[i]);
    return EXIT_SUCCESS;
}