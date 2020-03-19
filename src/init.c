/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** init tetris game
*/

#include <sys/ioctl.h>
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

bool init_term(struct termios *term_backup, char **env)
{
    char *term_env = my_getenv("TERM=", env);
    struct termios term;

    if (term_env == NULL) {
        my_put_error_str("TERM env not found\n");
        return true;
    }
    if (ioctl(0, TCGETS, &term) == -1) {
        my_put_error_str("Couldn't get termios structure\n");
        return true;
    }
    term.c_lflag &= ~(ICANON);
    term.c_lflag &= ~(ECHO);
    if (ioctl(0, TCGETS, term_backup) == -1 || ioctl(0, TCSETS, &term) == -1)
        return true;
    return false;
}

int init_boards(game_t *game)
{
    game->board = malloc(sizeof(char *) * game->flag->map_size[1]);
    game->colors = malloc(sizeof(int *) * game->flag->map_size[1]);

    if (game->board == NULL || game->colors == NULL)
        return EXIT_ERROR;
    for (int y = 0; y < game->flag->map_size[1]; y++) {
        game->board[y] = malloc(sizeof(char) * game->flag->map_size[0]);
        game->colors[y] = malloc(sizeof(int) * game->flag->map_size[0]);
        if (game->board[y] == NULL || game->colors[y] == NULL)
            return EXIT_ERROR;
        for (int x = 0; x < game->flag->map_size[0]; x++) {
            game->board[y][x] = EMPTY;
            game->colors[y][x] = EMPTY_COLOR;
        }
    }
    return EXIT_SUCCESS;
}

int init_ncurses(void)
{
    initscr();
    if (has_colors() == FALSE) {
        endwin();
        return EXIT_ERROR;
    }
    attron(A_NORMAL);
    start_color();
    return EXIT_SUCCESS;
}