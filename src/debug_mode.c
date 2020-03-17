/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** debug_mode
*/

#include <stdlib.h>
#include "tetris.h"
#include "my.h"

static void display_shape(char **shape)
{
    for (size_t i = 0; shape[i] != NULL; i++) {
        my_putstr(shape[i]);
        my_putstr("\n");
    }
}

static void display_tetriminos(tetriminos_t *tetriminos, int nb)
{
    for (int i = 0; i < nb; i++) {
        my_putstr("Tetriminos : Name ");
        my_putstr(tetriminos[i].name);
        my_putstr(" : ");
        if (tetriminos[i].width == 0) {
            my_putstr("Errror\n");
        } else {
            my_putstr("Size ");
            my_put_nbr(tetriminos[i].width);
            my_putstr("*");
            my_put_nbr(tetriminos[i].height);
            my_putstr(" : Color ");
            my_put_nbr(tetriminos[i].color);
            my_putstr(" :\n");
            display_shape(tetriminos[i].tetriminos);
        }
    }
}

static void display_key(flags_t *flag)
{
    my_putstr("Key Left : ");
    my_putstr(flag->left[0]);
    my_putstr("\n");
    my_putstr("Key Right : ");
    my_putstr(flag->right[0]);
    my_putstr("\n");
    my_putstr("Key Turn : ");
    my_putstr(flag->turn[0]);
    my_putstr("\n");
    my_putstr("Key Drop : ");
    my_putstr(flag->drop[0]);
    my_putstr("\n");
    my_putstr("Key Quit : ");
    my_putstr(flag->quit[0]);
    my_putstr("\n");
    my_putstr("Key Pause :");
    my_putstr(flag->pause[0]);
    my_putstr("\n");
}

static void display_game_info(game_t *game)
{
    my_putstr("Next : ");
    my_putstr((game->flag->without_next) ? "Yes\n" : "No\n");
    my_putstr("Level : ");
    my_put_nbr(game->flag->level);
    my_putstr("\n");
    my_putstr("Size : ");
    my_put_nbr(game->flag->map_size[0]);
    my_putstr("*");
    my_put_nbr(game->flag->map_size[1]);
    my_putstr("\n");
    my_putstr("Tetriminos : ");
    my_put_nbr(game->nb_tetriminos);
    my_putstr("\n");
}

int debug_mode(game_t *game)
{
    my_putstr("*** DEBUG MODE ***\n");
    display_key(game->flag);
    display_game_info(game);
    display_tetriminos(game->tetriminos, game->nb_tetriminos);
    my_putstr("Press any key to start Tetris\n");
    return EXIT_SUCCESS;
}