/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetris game
*/

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include "tetris.h"
#include "my.h"

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

static int save_high_score(int highscore)
{
    int fd = open(".highscore", O_RDWR);
    char *highscore_str = my_int_to_str(highscore);

    if (highscore_str == NULL)
        return EXIT_ERROR;
    write(fd, highscore_str, my_strlen(highscore_str));
    close(fd);
    free(highscore_str);
    return EXIT_SUCCESS;
}

static void end_game(struct termios *term_backup, game_t *game)
{
    destroy_game(*game);
    ioctl(0, TCSETS, term_backup);
    if (game->stat.score > game->stat.high_score)
        save_high_score(game->stat.score);
}

int tetris(int argc, char **argv, char **env)
{
    game_t game = {};
    struct termios term_backup = {};
    int exit_value;

    if (create_tetriminos("./tetriminos/", &game) == EXIT_ERROR)
        return EXIT_ERROR;
    game.flag = get_flags(argc, argv, env);
    if (game.flag == NULL) {
        put_file(argv[0]);
        destroy_game(game);
        return EXIT_ERROR;
    }
    exit_value = do_first_flags(argv[0], &term_backup, &game, env);
    if (exit_value != EXIT_SUCCESS)
        return exit_value;
    exit_value = play_game(&game);
    end_game(&term_backup, &game);
    return exit_value;
}