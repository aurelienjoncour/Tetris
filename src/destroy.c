/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** destroy all
*/

#include "tetris.h"

void destroy_game(game_t game)
{
    free_flags_struct(game.flag);
    destroy_tetriminos(game.tetriminos, game.nb_tetriminos);
    delwin(game.wins.game);
    delwin(game.wins.next);
    delwin(game.wins.stat);
    delwin(game.wins.tittle);
}
