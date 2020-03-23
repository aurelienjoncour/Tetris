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

#define BACKGROUND_COLOR COLOR_BLACK
#define EMPTY ' '
#define EMPTY_COLOR COLOR_BLACK

typedef struct flags_s
{
    bool help;
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

typedef struct tetrimino_s {
    char *name;
    char **tetrimino;
    char **tetrimino_2;
    char **tetrimino_3;
    char **tetrimino_4;
    int width;
    int height;
    int color;
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
} windows_t;

typedef struct game_stat {
    int high_score;
    int score;
    int lines_;
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
} game_t;

int tetris(int argc, char **argv, char **env);
char *my_getenv(char const *var, char **env);
bool init_term(struct termios *term_backup, char **env);

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

void debug_mode(game_t *game);

int play_game(game_t *game);
int init_boards(game_t *game);
int init_ncurses(void);
int init_all_window(game_t *game);
int init_wins(game_t *game);
int init_stat(game_t *game);
int init_next(game_t *game);
void destroy_game(game_t game);
int get_next(falling_t *fall, game_t *game);

void print_board(falling_t fall, game_t game);
void print_info(game_t game);
void print_next(game_t *game);

int rotate_2(tetrimino_t *tetriminos, int index, char **copy);
int rotate_3(tetrimino_t *tetriminos, int index, char **copy);
int rotate_4(tetrimino_t *tetriminos, int index, char **copy);
int rotate_tetriminos(tetrimino_t *tetriminos, int nb_tetriminos);

int check_full_line(game_t *game);

#endif