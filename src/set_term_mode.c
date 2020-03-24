/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** set_term_mode
*/

#include <sys/ioctl.h>
#include "tetris.h"

bool set_term_mode(bool toggle)
{
    static struct termios old_term;
    struct termios new_term;

    if (!toggle) {
        if (ioctl(0, TCGETS, &old_term) || ioctl(0, TCGETS, &new_term))
            return true;
        new_term.c_lflag &= ~ECHO;
        new_term.c_lflag &= ~ICANON;
        new_term.c_cc[VMIN] = 0;
        new_term.c_cc[VTIME] = 1;
        if (ioctl(0, TCSETS, &new_term))
            return true;
    } else
        if (ioctl(0, TCSETS, &old_term))
            return true;
    return false;
}