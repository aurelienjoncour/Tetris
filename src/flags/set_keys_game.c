/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** set keys game
*/

#include "my.h"
#include "tetris.h"

int set_key_quit(char *arg, flags_t *flags)
{
    if (arg == NULL || arg[0] == '=')
        return EXIT_ERROR;
    for (int i = 0; flags->quit[i] != NULL; i++)
        free(flags->quit[i]);
    free(flags->quit);
    flags->quit = malloc(sizeof(char *) * 2);
    if (flags->quit == NULL)
        return EXIT_ERROR;
    flags->quit[0] = my_strdup(arg);
    flags->quit[1] = NULL;
    if (flags->quit[0] == NULL)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

int set_key_pause(char *arg, flags_t *flags)
{
    if (arg == NULL || arg[0] == '=')
        return EXIT_ERROR;
    for (int i = 0; flags->pause[i] != NULL; i++)
        free(flags->pause[i]);
    free(flags->pause);
    flags->pause = malloc(sizeof(char *) * 2);
    if (flags->pause == NULL)
        return EXIT_ERROR;
    flags->pause[0] = my_strdup(arg);
    flags->pause[1] = NULL;
    if (flags->pause[0] == NULL)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

int set_map_size(char *arg, flags_t *flags)
{
    char **array = my_str_to_array(arg, "{};, ", false);

    if (arg == NULL || array == NULL)
        return EXIT_ERROR;
    for (int i = 0; i < 2; i++)
        if (array[i] == NULL)
            return EXIT_ERROR;
    if (array[2] != NULL || !my_str_isnum(array[0]) || !my_str_isnum(array[1]))
        return EXIT_ERROR;
    flags->map_size[0] = my_getnbr(array[0]);
    flags->map_size[1] = my_getnbr(array[1]);
    return EXIT_SUCCESS;
}