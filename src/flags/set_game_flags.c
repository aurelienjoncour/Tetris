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

int set_level(char *arg, flags_t *flags)
{
    if (allow_char(arg, "1234567890")) {
        return EXIT_ERROR;
    }
    flags->level = my_getnbr(arg);
    if (flags->level < 1)
        return EXIT_ERROR;
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