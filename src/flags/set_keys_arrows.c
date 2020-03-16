/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** set arrows keys
*/

#include "my.h"
#include "tetris.h"

int set_key_left(char *arg, flags_t *flags)
{
    if (arg == NULL)
        return EXIT_ERROR;
    for (int i = 0; flags->left[i] != NULL; i++)
        free(flags->left[i]);
    free(flags->left);
    flags->left = my_str_to_array(arg, ";, ", false);
    if (flags->left == NULL)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

int set_key_right(char *arg, flags_t *flags)
{
    if (arg == NULL)
        return EXIT_ERROR;
    for (int i = 0; flags->right[i] != NULL; i++)
        free(flags->right[i]);
    free(flags->right);
    flags->right = my_str_to_array(arg, ";, ", false);
    if (flags->right == NULL)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

int set_key_turn(char *arg, flags_t *flags)
{
    if (arg == NULL)
        return EXIT_ERROR;
    for (int i = 0; flags->turn[i] != NULL; i++)
        free(flags->turn[i]);
    free(flags->turn);
    flags->turn = my_str_to_array(arg, ";, ", false);
    if (flags->turn == NULL)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

int set_key_drop(char *arg, flags_t *flags)
{
    if (arg == NULL)
        return EXIT_ERROR;
    for (int i = 0; flags->drop[i] != NULL; i++)
        free(flags->drop[i]);
    free(flags->drop);
    flags->drop = my_str_to_array(arg, "={};, ", false);
    if (flags->drop == NULL)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}