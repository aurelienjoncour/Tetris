/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetris game
*/

#include "tetris.h"

int tetris(int argc, char **argv)
{
    game_t game = {};
    struct termios term_backup = {};

    create_tetriminos("./tetriminos/", &game);
    game.flag = get_flags(argc, argv);
    if (game.flag == NULL)
        return EXIT_ERROR;
    if (game.flag->debug)
        debug_mode(&game);
    if (init_term(&term_backup)) {
        free_flags_struct(game.flag);
        return EXIT_ERROR;
    }
    free_flags_struct(game.flag);
    tcsetattr(0, 0, &term_backup);
    return EXIT_SUCCESS;
}