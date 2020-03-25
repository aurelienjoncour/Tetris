/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** rotation_tetrimino
*/

#include <stdlib.h>
#include "tetris.h"

int first_rotation(game_t *game, falling_t *fall)
{
    int tmp = 0;

    fall->tetrimino.tetrimino = fall->tetrimino.tetrimino_2;
    tmp = fall->tetrimino.width;
    fall->tetrimino.width = fall->tetrimino.height;
    fall->tetrimino.height = tmp;
    fall->tetrimino.rotation++;
    print_board(*fall, game);
    return EXIT_SUCCESS;
}

int second_rotation(game_t *game, falling_t *fall)
{
    int tmp = 0;

    fall->tetrimino.tetrimino = fall->tetrimino.tetrimino_3;
    tmp = fall->tetrimino.width;
    fall->tetrimino.width = fall->tetrimino.height;
    fall->tetrimino.height = tmp;
    fall->tetrimino.rotation++;
    print_board(*fall, game);
    return EXIT_SUCCESS;
}

int third_rotation(game_t *game, falling_t *fall)
{
    int tmp = 0;

    fall->tetrimino.tetrimino = fall->tetrimino.tetrimino_4;
    tmp = fall->tetrimino.width;
    fall->tetrimino.width = fall->tetrimino.height;
    fall->tetrimino.height = tmp;
    fall->tetrimino.rotation++;
    print_board(*fall, game);
    return EXIT_SUCCESS;
}

int last_rotation(game_t *game, falling_t *fall, char **save_initial)
{
    int tmp = 0;

    fall->tetrimino.rotation = 0;
    fall->tetrimino.tetrimino = save_initial;
    tmp = fall->tetrimino.width;
    fall->tetrimino.width = fall->tetrimino.height;
    fall->tetrimino.height = tmp;
    print_board(*fall, game);
    return EXIT_SUCCESS;
}