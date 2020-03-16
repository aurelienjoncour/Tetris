/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** get flags
*/

#include "my.h"
#include "tetris.h"

typedef struct opt_func_s
{
    int (*func)(char *arg, flags_t *flags);
    int opt;
} opt_func_t;

const struct option optslong[] = {
    {"help", no_argument, NULL, 'h'},
    {"level", required_argument, NULL, 'L'},
    {"key-left", required_argument, NULL, 'l'},
    {"key-right", required_argument, NULL, 'r'},
    {"key-turn", required_argument, NULL, 't'},
    {"key-drop", required_argument, NULL, 'd'},
    {"key-quit", required_argument, NULL, 'q'},
    {"key-pause", required_argument, NULL, 'p'},
    {"map-size", required_argument, NULL, 0},
    {"without-next", no_argument, NULL, 'w'},
    {"debug", no_argument, NULL, 'D'},
    {0, 0, 0, 0}
};

const opt_func_t opt_func[] = {
    {&put_help, 'h'},
    {&set_level, 'L'},
    {&set_key_left, 'l'},
    {&set_key_right, 'r'},
    {&set_key_turn, 't'},
    {&set_key_drop, 'd'},
    {&set_key_quit, 'q'},
    {&set_key_pause, 'p'},
    {&set_map_size, 0},
    {&toggle_next, 'w'},
    {&toggle_debug, 'D'},
    {NULL, 0}
};

static char **set_flag_keys(char *value)
{
    char **tab = malloc(sizeof(char *) * 2);

    if (tab == NULL)
        return NULL;
    tab[1] = NULL;
    tab[0] = my_strdup(value);
    if (tab[0] == NULL)
        return NULL;
    return tab;
}

static flags_t *init_flags(void)
{
    flags_t *flags = malloc(sizeof(flags_t));

    if (flags == NULL)
        return NULL;
    flags->left = set_flag_keys(DEF_LEFT);
    flags->right = set_flag_keys(DEF_RIGHT);
    flags->turn = set_flag_keys(DEF_TURN);
    flags->drop = set_flag_keys(DEF_DROP);
    flags->quit = set_flag_keys(DEF_QUIT);
    flags->pause = set_flag_keys(DEF_PAUSE);
    flags->map_size[0] = DEF_ROW;
    flags->map_size[1] = DEF_COL;
    if (!flags->left || !flags->right || !flags->turn || !flags->drop
    || !flags->quit || !flags->pause)
        return NULL;
    flags->level = DEF_LEVEL;
    flags->without_next = DEF_LEVEL;
    flags->debug = DEF_DEBUG;
    return flags;
}

flags_t *get_flags(int argc, char **argv)
{
    flags_t *flags = init_flags();
    int optsindex;
    int opt = -2;

    if (flags == NULL)
        return NULL;
    while (opt != -1) {
        for (int i = 0; opt != -2 && opt_func[i].func != NULL; i++)
            if (opt_func[i].opt == opt
            && opt_func[i].func(argv[optind - 1], flags) == EXIT_ERROR)
                return NULL;
        opt = getopt_long(argc, argv, "hL:l:r:t:d:q:p:s:wD",
                        optslong, &optsindex);
    }
    return flags;
}