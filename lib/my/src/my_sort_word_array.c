/*
** EPITECH PROJECT, 2019
** my_sort_word_array
** File description:
** sort the words received via my_str_to_word_array
*/

#include <stdlib.h>
#include "my.h"

static int my_array_len(char **array)
{
    int len = 0;

    for (; array[len] != 0; len++);
    return len;
}

void my_sort_word_array(char **array)
{
    bool swapped = true;
    char *tmp = NULL;
    int len = my_array_len(array);

    while (swapped == true) {
        swapped = false;
        for (int i = 0; i < len - 1; i++)
            if (my_strcmp(array[i], array[i + 1]) > 0) {
                tmp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = tmp;
                swapped = true;
            }
    }
}
