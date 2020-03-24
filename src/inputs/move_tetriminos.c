/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** move tetriminos
*/

#include "tetris.h"

int move_tetri_left(game_t *game, falling_t *fall)
{
    if (game->pause)
        return EXIT_SUCCESS;
    if (fall->x > 0)
        fall->x--;
    print_board(*fall, game);
    return EXIT_SUCCESS;
}

int move_tetri_right(game_t *game, falling_t *fall)
{
    if (game->pause)
        return EXIT_SUCCESS;
    if (fall->x + fall->tetrimino.width < game->flag->map_size[1])
        fall->x++;
    print_board(*fall, game);
    return EXIT_SUCCESS;
}

int move_tetri_turn(game_t *game, falling_t *fall)
{
    if (game->pause)
        return EXIT_SUCCESS;
    return EXIT_SUCCESS;
}

int move_tetri_drop(game_t *game, falling_t *fall)
{
    if (game->pause)
        return EXIT_SUCCESS;
    return EXIT_SUCCESS;
}
