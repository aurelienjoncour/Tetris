/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** display_windows
*/

#include "tetris.h"

void print_info(game_t *game)
{
    init_pair(1, COLOR_BLACK, BACKGROUND_COLOR);
    attron(COLOR_PAIR(1));
    mvwprintw(game->wins.stat, 1, 1, "                          ");
    mvwprintw(game->wins.stat, 2, 1, " High Score %14d", game->stat.high_score);
    mvwprintw(game->wins.stat, 3, 1, " Score %19d", game->stat.score);
    mvwprintw(game->wins.stat, 4, 1, "                          ");
    mvwprintw(game->wins.stat, 5, 1, " Lines %19d", game->stat.lines_);
    mvwprintw(game->wins.stat, 6, 1, " Level %19d", game->stat.level);
    mvwprintw(game->wins.stat, 7, 1, "                          ");
    mvwprintw(game->wins.stat, 8, 1, " Timer %19d", game->stat.timer);
    attroff(COLOR_PAIR(1));
    wrefresh(game->wins.stat);
}

void print_board(game_t *game)
{
    int x = 1;
    int y = 1;

    clear();
    for (int j = 0; j < game->flag->map_size[0]; j++, y++, x = 1) {
        for (int i = 0; i < game->flag->map_size[1]; i++, x++) {
            init_pair(1, game->colors[j][i], BACKGROUND_COLOR);
            attron(COLOR_PAIR(1));
            mvwprintw(game->wins.game, y, x, "%c", game->board[j][i]);
            attroff(COLOR_PAIR(1));
        }
    }
    wrefresh(game->wins.game);
}


void print_next(game_t *game)
{
    mvwprintw(game->wins.next, 0, 10, "Next");
    wrefresh(game->wins.next);
}