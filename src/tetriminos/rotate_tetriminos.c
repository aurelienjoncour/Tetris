/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** rotate_tetriminos
*/

#include <stdlib.h>
#include "tetris.h"

static char **malloc_word_array(int height, int width)
{
    char **word_array = malloc(sizeof(char *) * (height + 1));

    if (word_array == NULL)
        return NULL;
    for (int i = 0; i < height; i++) {
        word_array[i] = malloc(sizeof(char) * (width + 1));
        if (word_array[i] == NULL)
            return NULL;
    }
    word_array[height] = NULL;
    return word_array;
}

int rotate_2(tetrimino_t *tetriminos, int index, char **copy)
{
    int height = tetriminos[index].width;
    int width = tetriminos[index].height;
    int z = tetriminos[index].height - 1;

    tetriminos[index].tetrimino_2 = malloc_word_array(height, width);
    if (tetriminos[index].tetrimino_2 == NULL)
        return EXIT_FAILURE;
    for (int i = 0; i < height; i++) {
        z = tetriminos[index].height - 1;
        for (int j = 0; j < width; j++) {
            tetriminos[index].tetrimino_2[i][j] = copy[z][i];
            z--;
        }
        tetriminos[index].tetrimino_2[i][width] = '\0';
    }
    return EXIT_SUCCESS;
}

int rotate_3(tetrimino_t *tetriminos, int index, char **copy)
{
    int height = tetriminos[index].height;
    int width = tetriminos[index].width;
    int z = width - 1;
    int w = height - 1;

    tetriminos[index].tetrimino_3 = malloc_word_array(height, width);
    if (tetriminos[index].tetrimino_3 == NULL)
        return EXIT_FAILURE;
    for (int i = 0; i < height; i++) {
        z = width - 1;
        for (int j = 0; j < width; j++) {
            tetriminos[index].tetrimino_3[i][j] = copy[w][z];
            z--;
        }
        w--;
        tetriminos[index].tetrimino_3[i][width] = '\0';
    }
    return EXIT_SUCCESS;
}

int rotate_4(tetrimino_t *tetriminos, int index, char **copy)
{
    int height = tetriminos[index].width;
    int width = tetriminos[index].height;
    int z = tetriminos[index].width - 1;
    int w = 0;

    tetriminos[index].tetrimino_4 = malloc_word_array(height, width);
    if (tetriminos[index].tetrimino_4 == NULL)
        return EXIT_FAILURE;
    for (int i = 0; i < height; i++) {
        w = 0;
        for (int j = 0; j < width; j++) {
            tetriminos[index].tetrimino_4[i][j] = copy[w][z];
            w++;
        }
        tetriminos[index].tetrimino_4[i][width] = '\0';
        z--;
    }
    return EXIT_SUCCESS;
}
