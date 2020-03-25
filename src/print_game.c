/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** put game board
*/

#include "tetris.h"

static void put_falling(falling_t fall, game_t *game, bool put)
{
    if (fall.x < 0)
        return;
    for (int y = 0; y < fall.tetrimino.height; y++)
        for (int x = 0; fall.tetrimino.tetrimino[y][x] != '\0'; x++)
            game->board[fall.y + y][fall.x + x] =
                put ? fall.tetrimino.tetrimino[y][x] : EMPTY;
}

void print_board(falling_t fall, game_t *game)
{
    put_falling(fall, game, true);
    clear();
    for (int j = 0; j < game->flag->map_size[0]; j++) {
        for (int i = 0; i < game->flag->map_size[1]; i++) {
            init_pair(1, game->colors[j][i], BACKGROUND_COLOR);
            attron(COLOR_PAIR(1));
            mvwprintw(game->wins.game, j + 1, i + 1, "%c", game->board[j][i]);
            attroff(COLOR_PAIR(1));
        }
    }
    put_falling(fall, game, false);
    wrefresh(game->wins.game);
}