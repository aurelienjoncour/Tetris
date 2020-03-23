/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** my_int_to_str
*/

#include <stdlib.h>
#include "my.h"

static int nb_len(int nb)
{
    int len = 0;

    while (nb > 0) {
        nb /= 10;
        len++;
    }
    if (len == 0)
        return (1);
    return len;
}

static char *my_convert_nbr(unsigned int nb, char *str, int i)
{
    if (nb == 0) {
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    if (nb/10 > 0)
        my_convert_nbr(nb/10, str, i-1);
    str[i] = '0' + nb % 10;
    return str;
}

char *my_int_to_str(int nb)
{
    char *nb_str = malloc(sizeof(char) * (nb_len(nb) + 1));

    if (nb_str == NULL)
        return NULL;
    for (int j = 0; j < (nb_len(nb) + 1); j++)
        nb_str[j] = '\0';
    my_convert_nbr(nb, nb_str, nb_len(nb) - 1);
    nb_str[nb_len(nb)] = '\0';
    return nb_str;
}