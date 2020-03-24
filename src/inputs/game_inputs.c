/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** game inputs
*/

#include "tetris.h"

int game_quit(__attribute((unused))game_t *game,
            __attribute((unused))falling_t *fall)
{
    return EXIT_FAILURE;
}

int game_pause(game_t *game, __attribute((unused))falling_t *fall)
{
    game->pause = !game->pause;
    return EXIT_SUCCESS;
}