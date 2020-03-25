/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** display_windows
*/

#include "tetris.h"

static const char *t[] = {
    " _____",
    "|_   _|",
    "  | |",
    "  | |",
    "  | |",
    "  \\_/",
    NULL,
};

static const char *e[] =  {
    "  ___ ",
    " / _ \\",
    "|  __/",
    " \\___|",
    NULL,
};

static const char *t_2[] = {
    " _ ",
    "| |",
    "| |_ ",
    "| __|",
    "| |_ ",
    "\\__|",
    NULL,
};

static const char *r[] = {
    " _ __ ",
    "| '__|",
    "| |   ",
    "|_|   ",
    NULL,
};

static const char *i[] = {
    " _",
    "(_)",
    " _ ",
    "| |",
    "| |",
    "|_|",
    NULL,
};

static const char *s[] = {
    " ___",
    "/ __|",
    "\\__ \\",
    "|___/",
    NULL,
};

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

static void print_tittle_1(game_t *game)
{
    wattron(game->wins.tittle, COLOR_PAIR(COLOR_RED));
    for (size_t i = 0; t[i] != NULL; i++)
        mvwprintw(game->wins.tittle, i, 0, t[i]);
    wattroff(game->wins.tittle, COLOR_PAIR(COLOR_RED));
    wattron(game->wins.tittle, COLOR_PAIR(COLOR_YELLOW));
    for (size_t i = 0; e[i] != NULL; i++)
        mvwprintw(game->wins.tittle, i + 2, 5, e[i]);
    wattroff(game->wins.tittle, COLOR_PAIR(COLOR_YELLOW));
    wattron(game->wins.tittle, COLOR_PAIR(COLOR_BLUE));
    for (size_t i = 0; t_2[i] != NULL; i++)
        mvwprintw(game->wins.tittle, i, 11, t_2[i]);
    wattroff(game->wins.tittle, COLOR_PAIR(COLOR_BLUE));
}

void print_tittle(game_t *game)
{
    print_tittle_1(game);
    wattron(game->wins.tittle, COLOR_PAIR(COLOR_GREEN));
    for (size_t i = 0; r[i] != NULL; i++)
        mvwprintw(game->wins.tittle, i + 2, 16, r[i]);
    wattroff(game->wins.tittle, COLOR_PAIR(COLOR_GREEN));
    wattron(game->wins.tittle, COLOR_PAIR(COLOR_CYAN));
    for (size_t j = 0; i[j] != NULL; j++)
        mvwprintw(game->wins.tittle, j, 22, i[j]);
    wattroff(game->wins.tittle, COLOR_PAIR(COLOR_CYAN));
    wattron(game->wins.tittle, COLOR_PAIR(COLOR_MAGENTA));
    for (size_t i = 0; s[i] != NULL; i++)
        mvwprintw(game->wins.tittle, i + 2, 25, s[i]);
    wattroff(game->wins.tittle, COLOR_PAIR(COLOR_MAGENTA));
    wrefresh(game->wins.tittle);
}