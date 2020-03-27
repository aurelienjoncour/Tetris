/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** move tetriminos
*/

#include <unistd.h>
#include "tetris.h"

int move_tetri_left(game_t *game, falling_t *fall)
{
    if (game->pause)
        return EXIT_SUCCESS;
    if (fall->x > 0) {
        if (!check_hitbox_l(game, fall))
            fall->x--;
    }
    print_board(*fall, game);
    return EXIT_SUCCESS;
}

int move_tetri_right(game_t *game, falling_t *fall)
{
    if (game->pause)
        return EXIT_SUCCESS;
    if (fall->x + fall->tetrimino.width < game->flag->map_size[1]) {
        if (!check_hitbox_r(game, fall))
            fall->x++;
    }
    print_board(*fall, game);
    return EXIT_SUCCESS;
}

int move_tetri_turn(game_t *game, falling_t *fall)
{
    static char **save_initial = NULL;

    if (game->pause)
        return EXIT_SUCCESS;
    if (fall->tetrimino.rotation == 0) {
        save_initial = fall->tetrimino.tetrimino;
        return first_rotation(game, fall);
    }
    if (fall->tetrimino.rotation == 1)
        return second_rotation(game, fall);
    if (fall->tetrimino.rotation == 2)
        return third_rotation(game, fall);
    if (fall->tetrimino.rotation == 3)
        return last_rotation(game, fall, save_initial);
    return EXIT_SUCCESS;
}

int move_tetri_drop(game_t *game, falling_t *fall)
{
    if (game->pause)
        return EXIT_SUCCESS;
    while (fall->x >= 0) {
        fall_tetrimino(game, fall);
        usleep(20000);
    }
    return EXIT_SUCCESS;
}
