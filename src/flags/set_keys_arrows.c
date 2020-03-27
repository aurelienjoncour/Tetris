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
    if (arg == NULL || arg[0] == '=')
        return EXIT_ERROR;
    for (int i = 0; flags->left[i] != NULL; i++)
        free(flags->left[i]);
    free(flags->left);
    flags->left = malloc(sizeof(char *) * 2);
    if (flags->left == NULL)
        return EXIT_ERROR;
    flags->left[0] = my_strdup(arg);
    flags->left[1] = NULL;
    if (flags->left[0] == NULL)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

int set_key_right(char *arg, flags_t *flags)
{
    if (arg == NULL || arg[0] == '=')
        return EXIT_ERROR;
    for (int i = 0; flags->right[i] != NULL; i++)
        free(flags->right[i]);
    free(flags->right);
    flags->right = malloc(sizeof(char *) * 2);
    if (flags->right == NULL)
        return EXIT_ERROR;
    flags->right[0] = my_strdup(arg);
    flags->right[1] = NULL;
    if (flags->right[0] == NULL)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

int set_key_turn(char *arg, flags_t *flags)
{
    if (arg == NULL || arg[0] == '=')
        return EXIT_ERROR;
    for (int i = 0; flags->turn[i] != NULL; i++)
        free(flags->turn[i]);
    free(flags->turn);
    flags->turn = malloc(sizeof(char *) * 2);
    if (flags->turn == NULL)
        return EXIT_ERROR;
    flags->turn[0] = my_strdup(arg);
    flags->turn[1] = NULL;
    if (flags->turn[0] == NULL)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

int set_key_drop(char *arg, flags_t *flags)
{
    if (arg == NULL || arg[0] == '=')
        return EXIT_ERROR;
    for (int i = 0; flags->drop[i] != NULL; i++)
        free(flags->drop[i]);
    free(flags->drop);
    flags->drop = malloc(sizeof(char *) * 2);
    if (flags->drop == NULL)
        return EXIT_ERROR;
    flags->drop[0] = my_strdup(arg);
    flags->drop[1] = NULL;
    if (flags->drop[0] == NULL)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}