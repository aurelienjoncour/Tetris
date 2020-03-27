/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetris game
*/

#include <time.h>
#include "my.h"
#include "tetris.h"

static int update_clock(clock_t *time, game_t *game, falling_t *fall,
                        tetrimino_t next_tetri)
{
    clock_t current = clock();

    if (*time == -1 || current == -1)
        return EXIT_ERROR;
    if (current / (1000 / game->stat.level) - *time / (1000 / game->stat.level)
    > 0) {
        if (!game->pause && fall->x >= 0)
            fall_tetrimino(game, fall);
        game->stat.timer = *time / 1000;
        print_info(game);
        print_next(game, next_tetri);
        *time = clock();
    }
    return EXIT_SUCCESS;
}

int play_game(game_t *game)
{
    clock_t time = clock();
    falling_t fall = {{0}, -1, -1};
    tetrimino_t next_tetri = game->tetriminos[rand() % game->nb_tetriminos];
    int exit_value = EXIT_SUCCESS;

    if (init_boards(game) == EXIT_ERROR || init_all_window(game) == EXIT_ERROR)
        return EXIT_ERROR;
    print_info(game);
    print_next(game, next_tetri);
    print_tittle(game);
    while (get_next(&fall, game, &next_tetri) == EXIT_SUCCESS
    && exit_value == EXIT_SUCCESS) {
        exit_value = get_inputs(game, &fall);
        if (exit_value == EXIT_ERROR
        || update_clock(&time, game, &fall, next_tetri) == EXIT_ERROR)
            return EXIT_ERROR;
        check_full_line(game);
    }
    clear();
    return EXIT_SUCCESS;
}