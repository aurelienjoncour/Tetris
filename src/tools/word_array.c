/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** word_array
*/

#include <stdlib.h>
#include "my.h"

void free_twod_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

int word_array_len(char **array)
{
    int i = 0;

    for (i = 0; array[i] != NULL; i++);
    return i;
}

char **word_array_dup(char **env)
{
    char **dup;
    size_t size = word_array_len(env);

    dup = malloc(sizeof(char *) * (size + 1));
    if (dup == NULL)
        return NULL;
    for (int i = 0; env[i]; i++) {
        dup[i] = my_strdup(env[i]);
        if (dup[i] == NULL)
            return NULL;
    }
    dup[size] = NULL;
    return dup;
}

char **word_array_realloc(char **array)
{
    size_t size = word_array_len(array);
    char **dup = malloc(sizeof(char *) * (size + 2));

    if (dup == NULL)
        return NULL;
    for (int i = 0; array[i]; i++) {
        dup[i] = my_strdup(array[i]);
        if (dup[i] == NULL)
            return NULL;
    }
    dup[size] = NULL;
    dup[size + 1] = NULL;
    free_twod_array(array);
    return dup;
}