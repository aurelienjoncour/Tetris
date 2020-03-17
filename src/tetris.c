/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetris game
*/

#include "tetris.h"

int tetris(int argc, char **argv)
{
    flags_t *flags = get_flags(argc, argv);
    game_t game = {0};

    create_tetriminos("./tetriminos/", &game);
    game.flag = flags;
    if (flags == NULL)
        return EXIT_ERROR;
    if (game.flag->debug)
        debug_mode(&game);
    return EXIT_SUCCESS;
}