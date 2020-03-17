/*
** EPITECH PROJECT, 2019
** my_sort_word_array
** File description:
** sort the words received via my_str_to_word_array
*/

#include <my.h>

static int my_tab_len(char **tab)
{
    int len = 0;

    while (tab[len] != 0)
        len++;
    return (len);
}

int my_sort_word_array(char **tab)
{
    int swapped = 1;
    char *tmp = 0;
    int len = my_tab_len(tab);

    while (swapped == 1) {
        swapped = 0;
        for (int i = 0; i < len - 1; i++) {
            if (my_strcmp(tab[i], tab[i + 1]) > 0) {
                tmp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = tmp;
                swapped = 1;
            }
        }
    }
    return 0;
}
