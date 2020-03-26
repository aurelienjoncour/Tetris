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

static bool is_it_folder(const char *filename, char const *folder)
{
    struct stat buff;
    char filepath[PATH_MAX] = {0};

    my_strcpy(filepath, folder);
    my_strcat(filepath, filename);
    if (lstat(filepath, &buff) == -1)
        return true;
    if (S_ISDIR(buff.st_mode))
        return true;
    return false;
}

static char **read_folder(DIR *directory, struct dirent *dir_info,
char const *folder)
{
    char **tetriminos_files = malloc(sizeof(char *) * 2);

    if (tetriminos_files != NULL)
        tetriminos_files[0] = NULL;
    for (size_t i = 0; tetriminos_files != NULL && dir_info != NULL;) {
        if (is_it_folder(dir_info->d_name, folder) == false) {
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
    return read_folder(directory, dir_info, folder);
}