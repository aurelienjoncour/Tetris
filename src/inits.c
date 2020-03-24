/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** init tetris game
*/

#include <sys/ioctl.h>
#include "my.h"
#include "tetris.h"

char *my_getenv(char const *var, char **env)
{
    int n = my_strlen(var);

    for (int i = 0; env[i]; i++)
        if (!my_strncmp(var, env[i], n))
            return env[i] + n;
    return NULL;
}

int init_ncurses(void)
{
    curs_set(0);
    if (has_colors() == FALSE) {
        endwin();
        return EXIT_ERROR;
    }
    attron(A_NORMAL);
    start_color();
    return EXIT_SUCCESS;
}

bool init_term(char **env)
{
    char *term_env = my_getenv("TERM=", env);
    char *keypad_mode = tigetstr("smkx");

    if (term_env == NULL || keypad_mode == NULL)
        return true;
    putp(keypad_mode);
    initscr();
    set_term_mode(false);
    init_ncurses();
    return false;
}

int init_boards(game_t *game)
{
    game->board = malloc(sizeof(char *) * game->flag->map_size[0]);
    game->colors = malloc(sizeof(int *) * game->flag->map_size[0]);

    if (game->board == NULL || game->colors == NULL)
        return EXIT_ERROR;
    for (int y = 0; y < game->flag->map_size[0]; y++) {
        game->board[y] = malloc(sizeof(char) * game->flag->map_size[1]);
        game->colors[y] = malloc(sizeof(int) * game->flag->map_size[1]);
        if (game->board[y] == NULL || game->colors[y] == NULL)
            return EXIT_ERROR;
        for (int x = 0; x < game->flag->map_size[1]; x++) {
            game->board[y][x] = EMPTY;
            game->colors[y][x] = EMPTY_COLOR;
        }
    }
    return EXIT_SUCCESS;
}

int init_all_window(game_t *game)
{
    if (init_wins(game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (init_stat(game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (init_next(game) == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}