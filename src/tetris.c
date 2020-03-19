/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetris game
*/

#include <sys/ioctl.h>
#include "tetris.h"

static int do_first_flags(char *binary, struct termios *term_backup,
                        game_t *game, char **env)
{
    if (game->flag->help) {
        free_flags_struct(game->flag);
        if (put_file(binary) == EXIT_ERROR)
            return EXIT_ERROR;
        return -1;
    }
    if (init_term(term_backup, env)) {
        free_flags_struct(game->flag);
        return EXIT_ERROR;
    }
    if (game->flag->debug)
        debug_mode(game);
    return EXIT_SUCCESS;
}

int tetris(int argc, char **argv, char **env)
{
    game_t game = {};
    struct termios term_backup = {};
    int exit_value;

    if (create_tetriminos("./tetriminos/", &game) == EXIT_ERROR)
        return EXIT_ERROR;
    game.flag = get_flags(argc, argv, env);
    if (game.flag == NULL)
        return EXIT_ERROR;
    exit_value = do_first_flags(argv[0], &term_backup, &game, env);
    if (exit_value != EXIT_SUCCESS)
        return exit_value;
    free_flags_struct(game.flag);
    ioctl(0, TCSETS, &term_backup);
    return exit_value;
}