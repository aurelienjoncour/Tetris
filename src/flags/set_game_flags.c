/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** key arrows
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "my.h"
#include "tetris.h"

static void delete_index(char *str, int i)
{
    for (; str[i] != '\0'; i++)
        str[i] = str[i + 1];
}

int set_level(char *arg, flags_t *flags)
{
    for (int i = 0; arg[i] != '\0'; i++)
        if (arg[i] < '0' || arg[i] > '9')
            delete_index(arg, i--);
    flags->level = my_getnbr(arg);
    return EXIT_SUCCESS;
}

int toggle_help(__attribute((unused))char *arg, flags_t *flags)
{
    flags->help = !flags->help;
    return EXIT_SUCCESS;
}

int toggle_next(__attribute((unused))char *arg, flags_t *flags)
{
    flags->without_next = !flags->without_next;
    return EXIT_SUCCESS;
}

int toggle_debug(__attribute((unused))char *arg, flags_t *flags)
{
    flags->debug = !flags->debug;
    return EXIT_SUCCESS;
}