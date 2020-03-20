/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** rotate_all_tetriminos
*/

#include <stdio.h>
#include "tetris.h"

static char **copy_tetrimino(tetrimino_t *tetriminos, int index)
{
    char **tetrimino = malloc(sizeof(char *) * (tetriminos[index].height + 1));

    if (tetrimino == NULL)
        return NULL;
    for (int i = 0; i < tetriminos[index].height; i++) {
        tetrimino[i] = malloc(sizeof(char) * (tetriminos[index].width + 1));
        for (int j = 0; j < tetriminos[index].width; j++) {
            tetrimino[i][j] = ' ';
        }
        tetrimino[i][tetriminos[index].width] = '\0';
    }
    tetrimino[tetriminos[index].height] = NULL;
    for (int i = 0; tetriminos[index].tetrimino[i] != NULL; i++) {
        for (int j = 0; tetriminos[index].tetrimino[i][j] != '\0'; j++) {
            tetrimino[i][j] = tetriminos[index].tetrimino[i][j];
        }
    }
    return tetrimino;
}

int rotate_tetriminos(tetrimino_t *tetriminos, int nb_tetriminos)
{
    char **copy = NULL;

    for (int i = 0; i < nb_tetriminos; i++) {
        copy = copy_tetrimino(tetriminos, i);
        if (copy == NULL)
            return EXIT_ERROR;
        if (rotate_2(tetriminos, i, copy) != EXIT_SUCCESS)
            return EXIT_ERROR;
        if (rotate_3(tetriminos, i, copy) != EXIT_SUCCESS)
            return EXIT_ERROR;
        if (rotate_4(tetriminos, i, copy) != EXIT_SUCCESS)
            return EXIT_ERROR;
        free_twod_array(copy);
    }
    return 0;
}