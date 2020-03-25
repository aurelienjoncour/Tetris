/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** display_windows
*/

#include "tetris.h"

void print_info(game_t *game)
{
    mvwprintw(game->wins.stat, 1, 1, "                          ");
    mvwprintw(game->wins.stat, 2, 1, " High Score %14d", game->stat.high_score);
    mvwprintw(game->wins.stat, 3, 1, " Score %19d", game->stat.score);
    mvwprintw(game->wins.stat, 4, 1, "                          ");
    mvwprintw(game->wins.stat, 5, 1, " Lines %19d", game->stat.my_lines);
    mvwprintw(game->wins.stat, 6, 1, " Level %19d", game->stat.level);
    mvwprintw(game->wins.stat, 7, 1, "                          ");
    mvwprintw(game->wins.stat, 8, 1, " Timer %19d", game->stat.timer);
    wrefresh(game->wins.stat);
}

void print_next(game_t *game)
{
    mvwprintw(game->wins.next, 0, 10, "Next");
    wrefresh(game->wins.next);
}