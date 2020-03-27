/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** check_valid_move
*/

#include "tetris.h"
#include "my.h"

static int len_tetrimino_r(char *str)
{
    int len = my_strlen(str);

    for (int i = len; i > 1; i--) {
        if (str[i - 1] == '*')
            return i;
    }
    return 1;
}

int check_hitbox_r(game_t *game, falling_t *fall)
{
    int max_indice = 0;

    for (size_t i = 0; fall->tetrimino.tetrimino[i] != NULL; i++) {
        max_indice = len_tetrimino_r(fall->tetrimino.tetrimino[i]) + fall->x;
        if (game->board[fall->y + i][max_indice] == '*')
            return true;
    }
    return false;
}

static int len_tetrimino_l(char *str)
{
    if (str[0] == ' ')
        return 0;
    return 1;
}

int check_hitbox_l(game_t *game, falling_t *fall)
{
    int min_indice = 0;

    for (size_t i = 0; fall->tetrimino.tetrimino[i] != NULL; i++) {
        min_indice = len_tetrimino_l(fall->tetrimino.tetrimino[i]);
        if (min_indice && game->board[fall->y + i][fall->x - 1] == '*')
            return true;
    }
    return false;
}
