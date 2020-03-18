/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** header
*/

#include <stdlib.h>
#include <stdbool.h>
#include <getopt.h>

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

typedef struct tetriminos {
    char *name;
    char **tetriminos;
    int width;
    int height;
    int color;

} tetriminos_t;

typedef struct game {
    tetriminos_t *tetriminos;
    int nb_tetriminos;
    flags_t *flag;
} game_t;

int tetris(int argc, char **argv);
flags_t *get_flags(int argc, char **argv);

int put_help(char *arg,
            flags_t *flags);
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

bool allow_char(char *script, char *allow_char);
char **read_entiere_file(const char *filepath);

char **get_tetriminos_list(char const *folder);
void parse_tetriminos(const char *filename, const char *folder,
tetriminos_t *tetriminos, size_t i);
bool check_error_script(char **file, tetriminos_t *tetriminos, int index);
int create_tetriminos(char const *folder, game_t *a);
void destroy_tetriminos(tetriminos_t *tetriminos, int nb_tetriminos);

int debug_mode(game_t *game);

#endif