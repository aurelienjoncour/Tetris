/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** check_full_line
*/

#include <stdlib.h>
#include "tetris.h"
#include "my.h"

static void cpy_colors_lines(game_t *game, int lines_m)
{
    for (int i = lines_m; i > 1; i--) {
        for (int j = 0; game->board[i][j] != '\0'; j++)
            game->colors[i][j] = game->colors[i - 1][j];
    }
}

static int remove_lines(game_t *game, int lines_m)
{
    game->stat.my_lines++;
    if (game->stat.my_lines % 10 == 0)
        game->stat.level++;
    for (int i = lines_m; i > 1; i--) {
        free(game->board[i]);
        game->board[i] = my_strdup(game->board[i - 1]);
        if (game->board[i] == NULL)
            return EXIT_ERROR;
    }
    cpy_colors_lines(game, lines_m);
    for (size_t i = 0; game->board[0][i] != '\0'; i++) {
        game->board[0][i] = ' ';
        game->colors[0][i] = EMPTY_COLOR;
    }
    return EXIT_SUCCESS;
}

int check_full_line(game_t *game)
{
    int lines_m = game->flag->map_size[0];
    int cols_m = game->flag->map_size[1];
    int nb_block = 0;

    for (int i = lines_m - 1; i > 0; i--) {
        nb_block = 0;
        for (int j = 0; game->board[i][j] != '\0'; j++)
            if (game->board[i][j] == '*')
                nb_block++;
        if (nb_block == cols_m) {
            if (remove_lines(game, i) != EXIT_SUCCESS)
                return EXIT_ERROR;
            i--;
        }
    }
    return EXIT_SUCCESS;
}

