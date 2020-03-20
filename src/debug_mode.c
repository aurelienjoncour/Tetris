/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** debug_mode
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

static void display_tetriminos(tetrimino_t *tetriminos, int nb)
{
    for (int i = 0; i < nb; i++) {
        my_putstr("Tetriminos : Name ");
        my_putstr(tetriminos[i].name);
        my_putstr(" : ");
        if (tetriminos[i].width == 0)
            my_putstr("Error\n");
        else {
            my_putstr("Size ");
            my_put_nbr(tetriminos[i].width);
            my_putstr("*");
            my_put_nbr(tetriminos[i].height);
            my_putstr(" : Color ");
            my_put_nbr(tetriminos[i].color);
            my_putstr(" :\n");
            for (size_t k = 0; tetriminos[i].tetrimino[k] != NULL; k++) {
                my_putstr(tetriminos[i].tetrimino[k]);
                my_putstr("\n");
            }
        }
    }
}

static void print_key(char *key)
{
    if (!my_strcmp(key, " ")) {
        my_putstr("(space)\n");
        return;
    }
    for (int i = 0; key[i]; i++) {
        if (key[i] == 27)
            my_putstr("^E");
        else
            my_putchar(key[i]);
    }
    my_putchar('\n');
}

static void display_key(flags_t *flag)
{
    my_putstr("Key Left : ");
    print_key(flag->left[0]);
    my_putstr("Key Right : ");
    print_key(flag->right[0]);
    my_putstr("Key Turn : ");
    print_key(flag->turn[0]);
    my_putstr("Key Drop : ");
    print_key(flag->drop[0]);
    my_putstr("Key Quit : ");
    print_key(flag->quit[0]);
    my_putstr("Key Pause : ");
    print_key(flag->pause[0]);
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

void debug_mode(game_t *game)
{
    my_putstr("*** DEBUG MODE ***\n");
    display_key(game->flag);
    display_game_info(game);
    display_tetriminos(game->tetriminos, game->nb_tetriminos);
    my_putstr("Press any key to start Tetris\n");
}