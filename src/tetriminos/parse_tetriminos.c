/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** parse_tetriminos
*/

#include "my.h"
#include "tetris.h"
#include "word_array.h"

static int init_error(tetrimino_t *tetriminos, int i,
                        char const *filename, char **file)
{
    free_twod_array(file);
    tetriminos[i].tetrimino = NULL;
    tetriminos[i].color = 0;
    tetriminos[i].width = 0;
    tetriminos[i].height = 0;
    tetriminos[i].name = my_strdup(filename);
    if (tetriminos[i].name == NULL)
        return EXIT_ERROR;
    for (size_t j = 0; tetriminos[i].name[j] != '\0'; j++)
        if (my_strcmp(tetriminos[i].name+j, ".tetrimino") == 0)
            tetriminos[i].name[j] = '\0';
    return EXIT_SUCCESS;
}

static char **get_tetriminos_files(const char *filename, const char *folder)
{
    char *filepath = my_strdupcat(2, folder, filename);
    char **file = NULL;

    if (filepath == NULL)
        return NULL;
    file = read_entiere_file(filepath);
    free(filepath);
    if (file == NULL || word_array_len(file) < 2) {
        free_twod_array(file);
        return NULL;
    }
    return file;
}

static int get_tetriminos_info(tetrimino_t *tetriminos, int i,
                                char **file, const char *filename)
{
    char **first_line = my_str_to_array(file[0], " ", false);

    if (first_line == NULL || word_array_len(first_line) != 3)
        return EXIT_ERROR;
    for (size_t j = 0; j < 3; j++)
        if (allow_char(first_line[j], "0123456789"))
            return EXIT_ERROR;
    tetriminos[i].width = my_getnbr(first_line[0]);
    tetriminos[i].height = my_getnbr(first_line[1]);
    tetriminos[i].color = my_getnbr(first_line[2]);
    free_twod_array(first_line);
    if (word_array_len(file) - 1 != tetriminos[i].height)
        return EXIT_ERROR;
    tetriminos[i].name = my_strdup(filename);
    if (tetriminos[i].name == NULL)
        return EXIT_ERROR;
    for (size_t j = 0; tetriminos[i].name[j] != '\0'; j++)
        if (my_strcmp(tetriminos[i].name+j, ".tetrimino") == 0)
            tetriminos[i].name[j] = '\0';
    return EXIT_SUCCESS;
}

static int get_tetriminos_shape(tetrimino_t *tetriminos, int i,
                                char **file)
{
    tetriminos[i].tetrimino = malloc(sizeof(char *) *
                                    (tetriminos[i].height + 1));
    if (tetriminos[i].tetrimino == NULL)
        return EXIT_ERROR;
    for (int j = 0; j < tetriminos[i].height + 1; j++)
        tetriminos[i].tetrimino[j] = NULL;
    for (int j = 1; j < word_array_len(file); j++) {
        tetriminos[i].tetrimino[j - 1] = my_strdup(clean_string(file[j]));
        if (tetriminos[i].tetrimino[j - 1] == NULL)
            return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

int parse_tetriminos(const char *filename, const char *folder,
                        tetrimino_t *tetriminos, int i)
{
    char **file = get_tetriminos_files(filename, folder);

    tetriminos[i].rotation = 0;
    if (file == NULL)
        return init_error(tetriminos, i, filename, file);
    if (get_tetriminos_info(tetriminos, i, file, filename) == EXIT_ERROR)
        return init_error(tetriminos, i, filename, file);
    if (check_error_script(file, tetriminos, i))
        return init_error(tetriminos, i, filename, file);
    if (get_tetriminos_shape(tetriminos, i, file) == EXIT_ERROR)
        return init_error(tetriminos, i, filename, file);
    free_twod_array(file);
    return EXIT_SUCCESS;
}