/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** get flags
*/

#include <getopt.h>
#include "my.h"
#include "tetris.h"

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
    {&toggle_help, 'h'},
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
    char **array = malloc(sizeof(char *) * 2);

    if (array == NULL)
        return NULL;
    array[1] = NULL;
    array[0] = my_strdup(value);
    if (array[0] == NULL)
        return NULL;
    return array;
}

static flags_t *init_flags(void)
{
    flags_t *flags = malloc(sizeof(flags_t));

    if (flags == NULL)
        return NULL;
    flags->left = set_flag_keys(tigetstr(DEF_LEFT));
    flags->right = set_flag_keys(tigetstr(DEF_RIGHT));
    flags->turn = set_flag_keys(tigetstr(DEF_TURN));
    flags->drop = set_flag_keys(tigetstr(DEF_DROP));
    flags->quit = set_flag_keys(DEF_QUIT);
    flags->pause = set_flag_keys(DEF_PAUSE);
    flags->map_size[0] = DEF_ROW;
    flags->map_size[1] = DEF_COL;
    if (!flags->left || !flags->right || !flags->turn || !flags->drop
    || !flags->quit || !flags->pause)
        return NULL;
    flags->level = DEF_LEVEL;
    flags->help = false;
    flags->without_next = DEF_LEVEL;
    flags->debug = DEF_DEBUG;
    return flags;
}

void free_flags_struct(flags_t *flags)
{
    if (flags == NULL)
        return;
    for (int i = 0; flags->left[i] != NULL; free(flags->left[i]), i++);
    free(flags->left);
    for (int i = 0; flags->right[i] != NULL; i++)
        free(flags->right[i]);
    free(flags->right);
    for (int i = 0; flags->turn[i] != NULL; i++)
        free(flags->turn[i]);
    free(flags->turn);
    for (int i = 0; flags->drop[i] != NULL; i++)
        free(flags->drop[i]);
    free(flags->drop);
    for (int i = 0; flags->quit[i] != NULL; i++)
        free(flags->quit[i]);
    free(flags->quit);
    for (int i = 0; flags->pause[i] != NULL; i++)
        free(flags->pause[i]);
    free(flags->pause);
    free(flags);
}

static bool valid_arg(int argc, char **argv)
{
    for (int i = 1; i < argc - 1; i++) {
        if (argv[i][0] == '-' && my_strlen(argv[i]) > 2  && argv[i][1] != '-'
            && argv[i+1][0] != '-')
            return false;
    }
    for (int i = 1; i < argc; i++)
        if (argv[i][0] != '-' && argv[i - 1][0] != '-')
            return false;
    return true;
}

flags_t *get_flags(int argc, char **argv, char **env)
{
    char *term = my_getenv("TERM=", env);
    flags_t *flags;
    int optsindex;
    int opt = -2;
    int error;

    if (term == NULL || setupterm(term, 1, &error) || !valid_arg(argc, argv))
        return NULL;
    flags = init_flags();
    if (flags == NULL)
        return NULL;
    while (opt != -1) {
        for (int i = 0; opt != -2 && opt_func[i].func != NULL; i++)
            if ((opt_func[i].opt == opt && opt_func[i].func(optarg,
            flags) == EXIT_ERROR) || opt == '?')
                return NULL;
        opt = getopt_long(argc, argv, "hL:l:r:t:d:q:p:s:wD",
                        optslong, &optsindex);
    }
    return flags;
}
