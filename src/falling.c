/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** manage falling tetrimino
*/

#include "tetris.h"

static bool can_spawn(falling_t *fall, game_t const *game)
{
    for (int y = 0; y < fall->tetrimino.height; y++)
        for (int x = 0; fall->tetrimino.tetrimino[y][x] != '\0'; x++)
            if (fall->tetrimino.tetrimino[y][x] != EMPTY
            && game->board[fall->y + y][fall->x + x] != EMPTY)
                return false;
    return true;
}

int get_next(falling_t *fall, game_t *game, tetrimino_t *new_tetri)
{
    if (fall->x <= -1) {
        fall->x = game->flag->map_size[1] / 2;
        fall->y = 0;
        fall->tetrimino = *new_tetri;
        if (!can_spawn(fall, game))
            return EXIT_FAILURE;
        print_board(*fall, game);
        do {
            *new_tetri = game->tetriminos[rand() % game->nb_tetriminos];
        } while (new_tetri->tetrimino == NULL);
    }
    return EXIT_SUCCESS;
}

static void stock_tetrimino(game_t *game, falling_t *fall)
{
    game->stat.score += 2;
    fall->y--;
    for (int y = 0; y < fall->tetrimino.height; y++)
        for (int x = 0; fall->tetrimino.tetrimino[y][x] != '\0'; x++) {
            game->board[fall->y + y][fall->x + x] =
                add_tetri(*fall, game, x, y);
            game->colors[fall->y + y][fall->x + x] =
                fall->tetrimino.tetrimino[y][x] != EMPTY ?
                fall->tetrimino.color : game->colors[fall->y + y][fall->x + x];
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
            if (fall->tetrimino.tetrimino[y][x] != EMPTY
            && game->board[fall->y + y][fall->x + x] != EMPTY) {
                stock_tetrimino(game, fall);
                return;
            }
    print_board(*fall, game);
}