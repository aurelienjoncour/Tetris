/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** destroy_tetriminos
*/

#include "tetris.h"
#include "word_array.h"

void destroy_tetriminos(tetriminos_t *tetriminos, int nb_tetriminos)
{
    for (int i = 0; i < nb_tetriminos; i++) {
        free_2d_array(tetriminos[i].tetriminos);
        free(tetriminos[i].name);
    }
    free(tetriminos);
}