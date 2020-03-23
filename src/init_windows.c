/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** init_windows
*/

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "tetris.h"
#include "my.h"

int init_wins(game_t *game)
{
    game->wins.game = newwin(game->flag->map_size[0] + 2,
                            game->flag->map_size[1] + 2,
                            tigetnum("lines") - game->flag->map_size[0] - 2, 29);
    if (game->wins.game == NULL)
        return EXIT_ERROR;
    box(game->wins.game, ACS_VLINE, ACS_HLINE);
    return EXIT_SUCCESS;
}

int init_stat(game_t *game)
{
    mode_t mode = S_IROTH | S_IRWXU;
    int fd = open(".highscore", O_RDONLY | O_CREAT, mode);
    char highscore_file[10] = {0};
    int read_size = 0;

    if (fd != -1)
        read_size = read(fd, &highscore_file, 10);
    close(fd);
    highscore_file[read_size] = '\0';
    game->wins.stat = newwin(10, 28, tigetnum("lines") - 10 , 0);
    if (game->wins.game == NULL)
        return EXIT_ERROR;
    box(game->wins.stat, ACS_VLINE, ACS_HLINE);
    game->stat.high_score = my_getnbr(highscore_file);
    game->stat.score = 0;
    game->stat.level = game->flag->level;
    game->stat.lines_ = 0;
    game->stat.timer = 0;
    return EXIT_SUCCESS;
}

int init_next(game_t *game)
{
    game->wins.next = newwin(10, 28, LINES - 20, 0);
    if (game->wins.next == NULL)
        return EXIT_ERROR;
    box(game->wins.next, ACS_VLINE, ACS_HLINE);
    return EXIT_SUCCESS;
}