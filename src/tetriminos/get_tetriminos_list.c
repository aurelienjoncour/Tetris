/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** get_tetriminos_list
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include "my.h"
#include "word_array.h"

static char **read_folder(DIR *directory, struct dirent *dir_info)
{
    char **tetriminos_files = malloc(sizeof(char *) * 2);

    tetriminos_files[0] = NULL;
    for (size_t i = 0; dir_info != NULL;) {
        if (dir_info->d_name[0] != '.') {
            tetriminos_files[i] = my_strdup(dir_info->d_name);
            tetriminos_files[i + 1] = NULL;
            if (tetriminos_files[i] == NULL)
                return NULL;
            tetriminos_files = word_array_realloc(tetriminos_files);
            i++;
        }
        dir_info = readdir(directory);
    }
    closedir(directory);
    return tetriminos_files;
}

char **get_tetriminos_list(char const *folder)
{
    DIR *directory;
    struct dirent *dir_info;
    struct stat stat_file;

    if (lstat(folder, &stat_file) == -1)
        return NULL;
    if (!S_ISDIR(stat_file.st_mode))
        return NULL;
    directory = opendir(folder);
    if (directory == NULL)
        return NULL;
    dir_info = readdir(directory);
    return read_folder(directory, dir_info);
}