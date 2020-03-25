/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** manage falling tetrimino
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

static void stock_tetrimino(game_t *game, falling_t *fall)
{
    fall->y--;
    for (int y = 0; y < fall->tetrimino.height; y++)
        for (int x = 0; fall->tetrimino.tetrimino[y][x] != '\0'; x++) {
            game->board[fall->y + y][fall->x + x] =
                game->board[fall->y + y][fall->x + x] == EMPTY
                ? fall->tetrimino.tetrimino[y][x]
                : game->board[fall->y + y][fall->x + x];
            game->colors[fall->y + y][fall->x + x] = fall->tetrimino.color;
        }
    fall->x = -1;
}

void fall_tetrimino(game_t *game, falling_t *fall)
{
    fall->y++;
    if (fall->y + fall->tetrimino.height > game->flag->map_size[0]) {
        stock_tetrimino(game, fall);
        return;
    }
    for (int y = 0; y < fall->tetrimino.height; y++)
        for (int x = 0; fall->tetrimino.tetrimino[y][x] != '\0'; x++)
            if (game->board[fall->y + y][fall->x + x] != EMPTY) {
                stock_tetrimino(game, fall);
                return;
            }
    print_board(*fall, game);
}