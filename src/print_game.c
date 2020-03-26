/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** put game board
*/

#include "tetris.h"

static char remove_tetri(falling_t fall, game_t *game, int x, int y)
{
    if (fall.tetrimino.tetrimino[y][x] != EMPTY)
        return EMPTY;
    return game->board[fall.y + y][fall.x + x];
}

char add_tetri(falling_t fall, game_t *game, int x, int y)
{
    if (fall.tetrimino.tetrimino[y][x] == EMPTY)
        return game->board[fall.y + y][fall.x + x];
    return fall.tetrimino.tetrimino[y][x];
}

static void put_falling(falling_t fall, game_t *game, bool put)
{
    if (fall.x < 0)
        return;
    for (int y = 0; y < fall.tetrimino.height; y++)
        for (int x = 0; fall.tetrimino.tetrimino[y][x] != '\0'; x++) {
            game->board[fall.y + y][fall.x + x] = put
                ? add_tetri(fall, game, x, y) : remove_tetri(fall, game, x, y);
            game->colors[fall.y + y][fall.x + x] = put ?
                (fall.tetrimino.tetrimino[y][x] != EMPTY ?
                    fall.tetrimino.color : game->colors[fall.y + y][fall.x + x])
                : game->colors[fall.y + y][fall.x + x];
        }
}

void print_board(falling_t fall, game_t *game)
{
    put_falling(fall, game, true);
    clear();
    for (int j = 0; j < game->flag->map_size[0]; j++) {
        for (int i = 0; i < game->flag->map_size[1]; i++) {
            wattron(game->wins.game, COLOR_PAIR(game->colors[j][i]));
            mvwprintw(game->wins.game, j + 1, i + 1, "%c", game->board[j][i]);
            wattroff(game->wins.game, COLOR_PAIR(game->colors[j][i]));
        }
    }
    put_falling(fall, game, false);
    wrefresh(game->wins.game);
}