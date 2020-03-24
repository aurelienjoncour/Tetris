/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** move tetriminos
*/

#include "tetris.h"

int move_tetri_left(game_t *game, falling_t *fall)
{
    if (fall->x > 0)
        fall->x--;
    print_board(*fall, game);
    return EXIT_SUCCESS;
}