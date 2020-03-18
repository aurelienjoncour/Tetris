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
    struct termios term_backup = {};

    if (flags == NULL || init_term(&term_backup)) {
        free_flags_struct(flags);
        return EXIT_ERROR;
    }
    free_flags_struct(flags);
    tcsetattr(0, 0, &term_backup);
    return EXIT_SUCCESS;
}