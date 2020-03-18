/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** init tetris game
*/

#include "my.h"
#include "tetris.h"

bool init_term(struct termios *term_backup)
{
    char *term_env = getenv("TERM");
    struct termios term;

    if (term_env == NULL) {
        my_put_error_str("TERM env not found\n");
        return true;
    }
    if (tgetent(NULL, term_env) <= 0) {
        my_put_error_str("Couldn't get TERM value\n");
        return true;
    }
    if (tcgetattr(0, &term) == -1) {
        my_put_error_str("Couldn't get termios structure\n");
        return true;
    }
    term.c_lflag &= ~(ICANON);
    term.c_lflag &= ~(ECHO);
    if (tcgetattr(0, term_backup) == -1 || tcsetattr(0, 0, &term) == -1)
        return true;
    return false;
}