/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetris main
*/

#include <time.h>
#include "tetris.h"

int main(int argc, char **argv, char **env)
{
    srand(time(NULL));
    return tetris(argc, argv, env);
}