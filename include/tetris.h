/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** header
*/

#include <stdlib.h>
#include <stdbool.h>
#include <getopt.h>
#include <term.h>

#ifndef TETRIS_H_
#define TETRIS_H_

#define EXIT_ERROR 84
#define USAGE_FILEPATH "./usage.txt"

#define DEF_LEVEL 1
#define DEF_LEFT "kcub1"
#define DEF_RIGHT "kcuf1"
#define DEF_TURN "kcuu1"
#define DEF_DROP "kcud1"
#define DEF_QUIT "q"
#define DEF_PAUSE " "
#define DEF_ROW 20
#define DEF_COL 10
#define DEF_WITHOUT_NEXT false
#define DEF_DEBUG false

typedef struct flags_s
{
    int level;
    char **left;
    char **right;
    char **turn;
    char **drop;
    char **quit;
    char **pause;
    int map_size[2];
    bool without_next;
    bool debug;
} flags_t;

int tetris(int argc, char **argv);
bool init_term(struct termios *term_backup);

flags_t *get_flags(int argc, char **argv);
void free_flags_struct(flags_t *flags);
int put_help(__attribute((unused))char *arg,
            __attribute((unused))flags_t *flags);
int set_level(char *arg, flags_t *flags);
int set_key_left(char *arg, flags_t *flags);
int set_key_right(char *arg, flags_t *flags);
int set_key_turn(char *arg, flags_t *flags);
int set_key_drop(char *arg, flags_t *flags);
int set_key_quit(char *arg, flags_t *flags);
int set_key_pause(char *arg, flags_t *flags);
int set_map_size(char *arg, flags_t *flags);
int toggle_next(char *arg, flags_t *flags);
int toggle_debug(char *arg, flags_t *flags);

#endif