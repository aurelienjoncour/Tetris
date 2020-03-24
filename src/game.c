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

static int update_clock(clock_t *time, game_t game, falling_t *fall)
{
    clock_t current = clock();

    if (*time == -1 || current == -1)
        return EXIT_ERROR;
    if (current / 1000 - *time / 1000 > 0) { //if (current / CLOCKS_PER_SEC - *time / CLOCKS_PER_SEC > 1) {
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
    char buff[100] = {0};
    size_t read_size = 0;
    falling_t fall = {{0}, -1, -1};

    if (init_boards(game) == EXIT_ERROR || init_all_window(game) == EXIT_ERROR)
        return EXIT_ERROR;
    print_info(*game);
    print_next(game);
    while (get_next(&fall, game) == EXIT_SUCCESS) {
        read_size = read(0, &buff, 10);
        buff[read_size] = '\0';
        if (!my_strcmp(buff, game->flag->quit[0]))
            break;
        if (update_clock(&time, *game, &fall) == EXIT_ERROR)
            return EXIT_ERROR;
    }
    clear();
    return EXIT_SUCCESS;
}