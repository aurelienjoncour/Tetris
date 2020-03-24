/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetris game
*/

#include <time.h>
#include "my.h"
#include "tetris.h"

static int update_clock(clock_t *time, game_t *game, falling_t *fall)
{
    clock_t current = clock();

    if (*time == -1 || current == -1)
        return EXIT_ERROR;
    if (current / 1000 - *time / 1000 > 0) {
        fall->y++;
        print_board(*fall, game);
        print_info(game);
        *time = clock();
    }
    return EXIT_SUCCESS;
}

int play_game(game_t *game)
{
    clock_t time = clock();
    falling_t fall = {{0}, -1, -1};
    int exit_value = EXIT_SUCCESS;

    if (init_boards(game) == EXIT_ERROR || init_all_window(game) == EXIT_ERROR)
        return EXIT_ERROR;
    print_info(game);
    print_next(game);
    while (get_next(&fall, game) == EXIT_SUCCESS
    && exit_value == EXIT_SUCCESS) {
        exit_value = get_inputs(game, &fall);
        if (exit_value == EXIT_ERROR
        || update_clock(&time, game, &fall) == EXIT_ERROR)
            return EXIT_ERROR;
    }
    clear();
    return EXIT_SUCCESS;
}