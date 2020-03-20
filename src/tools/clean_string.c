/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** clean_string
*/

#include "my.h"

char *clean_string(char *str)
{
    int i = my_strlen(str) - 1;

    for (; i > 0; i--) {
        if (str[i] == ' ')
            str[i] = '\0';
        else if (str[i] == '*')
            break;
    }
    return str;
}