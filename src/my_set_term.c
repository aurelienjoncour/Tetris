/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** my_set_term
*/

#include <sys/ioctl.h>
#include "tetris.h"

int my_set_term(int status)
{
    static struct termios old;
    struct termios new;

    if (status == 0) {
        if (ioctl(0, TCGETS, &old) || ioctl(0, TCGETS, &new))
            return 1;
        new.c_lflag &= ~ECHO;
        new.c_lflag &= ~ICANON;
        new.c_cc[VTIME] = 1;
        new.c_cc[VMIN] = 0;
        if (ioctl(0, TCSETS, &new))
            return 1;
    } else {
        if (ioctl(0, TCSETS, &old))
            return 1;
    }
    return 0;
}