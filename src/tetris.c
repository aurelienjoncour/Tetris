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

static int do_first_flags(char *binary, game_t *game)
{
    if (game->flag->help) {
        free_flags_struct(game->flag);
        if (put_file(binary) == EXIT_ERROR)
            return EXIT_ERROR;
        return -1;
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

static void end_game(game_t *game)
{
    destroy_game(*game);
    set_term_mode(true);
    endwin();
    if (game->stat.score > game->stat.high_score)
        save_high_score(game->stat.score);
}

static int fail_init_term(game_t *game)
{
    free_flags_struct(game->flag);
    endwin();
    set_term_mode(true);
    return EXIT_ERROR;
}

int tetris(int argc, char **argv, char **env)
{
    game_t game = {};
    int exit_value;

    if (create_tetriminos("./tetriminos/", &game) == EXIT_ERROR)
        return EXIT_ERROR;
    game.flag = get_flags(argc, argv, env);
    if (game.flag == NULL) {
        put_file(argv[0]);
        destroy_game(game);
        return EXIT_ERROR;
    }
    exit_value = do_first_flags(argv[0], &game);
    if (exit_value != EXIT_SUCCESS)
        return exit_value;
    if (init_term(env))
        return fail_init_term(&game);
    exit_value = play_game(&game);
    end_game(&game);
    return exit_value;
}