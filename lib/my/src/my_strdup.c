/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** allocate memory and copy a string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *dest;
    int const size = my_strlen(src);

    if (src == NULL)
        return NULL;
    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (dest == NULL)
        return NULL;
    for (int i = 0; i <= size; i++)
        dest[i] = src[i];
    return dest;
}
