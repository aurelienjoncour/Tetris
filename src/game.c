/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetris game
*/

#include "tetris.h"

static void print_board(game_t *game)
{
    clear();
    printw("/");
    for (int i = 0; i < game->flag->map_size[0]; i++)
        printw("-");
    printw("\\\n");
    for (int y = 0; y < game->flag->map_size[1]; y++) {
        printw("|");
        for (int x = 0; x < game->flag->map_size[0]; x++) {
            init_pair(1, game->colors[y][x], BACKGROUND_COLOR);
            attron(COLOR_PAIR(1));
            printw(&game->board[y][x]);
            attroff(COLOR_PAIR(1));
        }
        printw("|\n");
    }
    printw("\\");
    for (int i = 0; i < game->flag->map_size[0]; i++)
        printw("-");
    printw("/\n");
    refresh();
}

int play_game(game_t *game)
{
    clock_t time = clock();

    if (init_boards(game) == EXIT_ERROR || init_ncurses() == EXIT_ERROR)
        return EXIT_ERROR;
    print_board(game);
    clear();
    endwin();
    return EXIT_SUCCESS;
}