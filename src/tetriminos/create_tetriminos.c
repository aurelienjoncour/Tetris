/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetriminos
*/

#include <stdlib.h>
#include "my.h"
#include "word_array.h"
#include "tetris.h"

int create_tetriminos(char const *folder, game_t *a)
{
    char **filename = get_tetriminos_list(folder);
    size_t nb_tetriminos = 0;

    if (filename == NULL)
        return 0;
    nb_tetriminos = word_array_len(filename);
    my_sort_word_array(filename);
    a->tetriminos = malloc(sizeof(tetriminos_t) * (nb_tetriminos + 1));
    if (a->tetriminos == NULL)
        return 0;
    for (size_t i = 0; i < nb_tetriminos; i++) {
        parse_tetriminos(filename[i], folder, a->tetriminos, i);
    }
    a->nb_tetriminos = nb_tetriminos;
    free_2d_array(filename);
    return EXIT_SUCCESS;
}

