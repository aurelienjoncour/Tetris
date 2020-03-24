/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** get next tetrimino
*/

#include "tetris.h"

static bool can_spawn(tetrimino_t const new_tetri, game_t const *game)
{
    for (int i = 0; i < game->flag->map_size[1]; i++)
        if (game->board[new_tetri.height - 1][i] != EMPTY)
            return false;
    return true;
}

int get_next(falling_t *fall, game_t *game)
{
    tetrimino_t new_tetri = game->tetriminos[rand() % game->nb_tetriminos];

    if (fall->x <= -1) {
        while (new_tetri.tetrimino == NULL)
            new_tetri = game->tetriminos[rand() % game->nb_tetriminos];
        if (!can_spawn(new_tetri, game))
            return EXIT_FAILURE;
        fall->x = game->flag->map_size[1] / 2;
        fall->y = 0;
        fall->tetrimino = new_tetri;
        print_board(*fall, game);
    }
    return EXIT_SUCCESS;
}