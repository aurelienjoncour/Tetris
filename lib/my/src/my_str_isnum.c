/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** is a string of digits
*/

#include <stdlib.h>
#include <stdbool.h>

bool my_str_isnum(char const *str)
{
    if (str == NULL)
        return false;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return false;
    return true;
}