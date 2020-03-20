/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** check_error_script
*/

#include "my.h"
#include "tetris.h"

bool check_error_script(char **file, tetrimino_t *tetriminos, int index)
{
    if (tetriminos[index].color < 1 || tetriminos[index].color > 7)
        return true;
    for (size_t i = 1; file[i] != NULL; i++)
        if (allow_char(file[i], "* "))
            return true;
    for (size_t i = 1; file[i] != NULL; i++)
        if (my_strlen(file[i]) == tetriminos[index].width)
            return false;
    return true;
}