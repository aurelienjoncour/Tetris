/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** get inputs
*/

#include <unistd.h>
#include "tetris.h"
#include "my.h"

const input_func_t inputs_func[3] = {
    move_tetri_left,
    move_tetri_right,
    NULL/*,
    move_tetri_turn,
    move_tetri_drop,
    game_pause,
    game_quit*/
};

static int check_key(bool is_valid, game_t *game, falling_t *fall, int i)
{
    if (is_valid)
        return inputs_func[i](game, fall);
    return -1;
}

static int apply_inputs(char *buffer, game_t *game, falling_t *fall)
{
    flags_t *manage = game->flag;
    char **tmp;
    int exit_value = -1;

    for (int k = 0; buffer[0] != '\0' && inputs_func[k] != NULL; k++) {
        tmp = *(void **)manage;
        for (int i = 0; exit_value == -1 && tmp[i] != NULL; i++)
            exit_value = check_key(!my_strcmp(buffer, tmp[i]), game, fall, k);
        if (exit_value != -1)
            return exit_value;
        manage = (void *)manage + 8;
    }
    return EXIT_SUCCESS;
}

int get_inputs(game_t *game, falling_t *fall)
{
    char buffer[10];
    ssize_t read_size = read(0, &buffer, 10);

    if (read_size == -1)
        return EXIT_ERROR;
    buffer[read_size] = '\0';
    return apply_inputs(buffer, game, fall);
}