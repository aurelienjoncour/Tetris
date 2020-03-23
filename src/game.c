/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetris game
*/

#include <unistd.h>
#include <time.h>
#include "my.h"
#include "tetris.h"

static bool is_lose(void)
{
    return 0;
}

static void print_info(game_t *game)
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

static void print_board(game_t *game)
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

static int update_clock(clock_t *time, game_t *game)
{
    clock_t current = clock();

    if (*time == -1 || current == -1)
        return EXIT_ERROR;
    if (current / CLOCKS_PER_SEC - *time / CLOCKS_PER_SEC > 1) {
        print_board(game);
        print_info(game);
        *time = clock();
    }
    return EXIT_SUCCESS;
}

int play_game(game_t *game)
{
    clock_t time = clock();
    char buff[100] = {0};
    int read_size = 0;

    if (init_boards(game) == EXIT_ERROR || init_ncurses() == EXIT_ERROR
    || init_wins(game) == EXIT_ERROR || init_stat(game) == EXIT_ERROR)
        return EXIT_ERROR;
    print_board(game);
    print_info(game);
    while (!is_lose()) {
        read_size = read(0, &buff, 10);
        buff[read_size] = '\0';
        if (!my_strcmp(buff, game->flag->quit[0]))
            break;
        if (update_clock(&time, game) == EXIT_ERROR)
            return EXIT_ERROR;
    }
    clear();
    endwin();
    return EXIT_SUCCESS;
}