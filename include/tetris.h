/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** header
*/

#include <stdlib.h>
#include <stdbool.h>
#include <term.h>
#include <curses.h>

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

#define EMPTY ' '
#define EMPTY_COLOR COLOR_BLACK

typedef struct flags_s
{
    char **left;
    char **right;
    char **turn;
    char **drop;
    char **pause;
    char **quit;
    bool help;
    int level;
    int map_size[2];
    bool without_next;
    bool debug;
} flags_t;

typedef struct tetrimino_s {
    char *name;
    char **tetrimino;
    char **tetrimino_2;
    char **tetrimino_3;
    char **tetrimino_4;
    int width;
    int height;
    int color;
    int rotation;
} tetrimino_t;

typedef struct falling_s {
    tetrimino_t tetrimino;
    int x;
    int y;
} falling_t;

typedef struct windows_s
{
    WINDOW *game;
    WINDOW *stat;
    WINDOW *next;
    WINDOW *tittle;
} windows_t;

typedef struct game_stat {
    int high_score;
    int score;
    int my_lines;
    int level;
    int timer;
} game_stat_t;

typedef struct game {
    tetrimino_t *tetriminos;
    int nb_tetriminos;
    flags_t *flag;
    char **board;
    int **colors;
    windows_t wins;
    game_stat_t stat;
    bool pause;
} game_t;

typedef int (*input_func_t)(game_t *, falling_t *);

typedef struct opt_func_s
{
    int (*func)(char *arg, flags_t *flags);
    int opt;
} opt_func_t;

int tetris(int argc, char **argv, char **env);
void debug_mode(game_t *game);
char *my_getenv(char const *var, char **env);
bool init_term(char **env);
bool set_term_mode(bool toggle);

flags_t *get_flags(int argc, char **argv, char **env);
void free_flags_struct(flags_t *flags);
int put_file(char const *binary);
int toggle_help(__attribute((unused))char *arg, flags_t *flags);
int set_level(char *arg, flags_t *flags);
int set_key_left(char *arg, flags_t *flags);
int set_key_right(char *arg, flags_t *flags);
int set_key_turn(char *arg, flags_t *flags);
int set_key_drop(char *arg, flags_t *flags);
int set_key_quit(char *arg, flags_t *flags);
int set_key_pause(char *arg, flags_t *flags);
int set_map_size(char *arg, flags_t *flags);
int toggle_next(__attribute((unused))char *arg, flags_t *flags);
int toggle_debug(__attribute((unused))char *arg, flags_t *flags);

bool allow_char(char *script, char *allow_char);
char **read_entiere_file(const char *filepath);
char *clean_string(char *str);

char **get_tetriminos_list(char const *folder);
int parse_tetriminos(const char *filename, const char *folder,
                    tetrimino_t *tetrimino, int i);
bool check_error_script(char **file, tetrimino_t *tetrimino, int index);
int create_tetriminos(char const *folder, game_t *a);
void destroy_tetriminos(tetrimino_t *tetrimino, int nb_tetriminos);

int play_game(game_t *game);
int init_boards(game_t *game);
int init_ncurses(void);
int init_all_window(game_t *game);
int init_wins(game_t *game);
int init_stat(game_t *game);
int init_next(game_t *game);
int init_tittle(game_t *game);
void destroy_game(game_t game);
int get_next(falling_t *fall, game_t *game);
void fall_tetrimino(game_t *game, falling_t *fall);
char add_tetri(falling_t fall, game_t *game, int x, int y);

void print_board(falling_t fall, game_t *game);
void print_info(game_t *game);
void print_next(game_t *game);
void print_tittle(game_t *game);

int rotate_2(tetrimino_t *tetriminos, int index, char **copy);
int rotate_3(tetrimino_t *tetriminos, int index, char **copy);
int rotate_4(tetrimino_t *tetriminos, int index, char **copy);
int rotate_tetriminos(tetrimino_t *tetriminos, int nb_tetriminos);
int check_full_line(game_t *game);
int first_rotation(game_t *game, falling_t *fall);
int second_rotation(game_t *game, falling_t *fall);
int third_rotation(game_t *game, falling_t *fall);
int last_rotation(game_t *game, falling_t *fall, char **save_initial);

int get_inputs(game_t *game, falling_t *fall);
int move_tetri_left(game_t *game, falling_t *fall);
int move_tetri_right(game_t *game, falling_t *fall);
int move_tetri_drop(game_t *game, falling_t *fall);
int move_tetri_turn(game_t *game, falling_t *fall);
int game_pause(game_t *game, __attribute((unused))falling_t *fall);
int game_quit(__attribute((unused))game_t *game,
            __attribute((unused))falling_t *fall);

#endif