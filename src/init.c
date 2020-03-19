/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** init tetris game
*/

#include <sys/ioctl.h>
#include <sys/ioctl.h>
#include "my.h"
#include "tetris.h"

char *my_getenv(char const *var, char **env)
{
    int n = my_strlen(var);

    for (int i = 0; env[i]; i++)
        if (!my_strncmp(var, env[i], n))
            return env[i] + n;
    return NULL;
}

bool init_term(struct termios *term_backup, char **env)
{
    char *term_env = my_getenv("TERM=", env);
    struct termios term;

    if (term_env == NULL) {
        my_put_error_str("TERM env not found\n");
        return true;
    }
    if (tgetent(NULL, term_env) <= 0) {
        my_put_error_str("Couldn't get TERM value\n");
        return true;
    }
    if (ioctl(0, TCGETS, &term) == -1) {
        my_put_error_str("Couldn't get termios structure\n");
        return true;
    }
    term.c_lflag &= ~(ICANON);
    term.c_lflag &= ~(ECHO);
    if (ioctl(0, TCGETS, term_backup) == -1 || ioctl(0, TCSETS, &term) == -1)
        return true;
    return false;
}