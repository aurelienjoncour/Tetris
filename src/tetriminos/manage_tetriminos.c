/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetriminos
*/

#include "my.h"
#include "tetris.h"
#include "word_array.h"

void destroy_tetriminos(tetriminos_t *tetriminos, int nb_tetriminos)
{
    for (int i = 0; i < nb_tetriminos; i++) {
        free_twod_array(tetriminos[i].tetriminos);
        free(tetriminos[i].name);
    }
    free(tetriminos);
}

int create_tetriminos(char const *folder, game_t *a)
{
    char **filename = get_tetriminos_list(folder);

    if (filename == NULL)
        return EXIT_ERROR;
    a->nb_tetriminos = word_array_len(filename);
    my_sort_word_array(filename);
    a->tetriminos = malloc(sizeof(tetriminos_t) * (a->nb_tetriminos + 1));
    if (a->tetriminos == NULL)
        return EXIT_ERROR;
    for (int i = 0; i < a->nb_tetriminos; i++)
        if (parse_tetriminos(filename[i], folder, a->tetriminos, i)
        == EXIT_ERROR)
            return EXIT_ERROR;
    free_twod_array(filename);
    return EXIT_SUCCESS;
}