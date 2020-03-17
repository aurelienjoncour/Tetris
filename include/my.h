/*
** EPITECH PROJECT, 2019
** my lib .h
** File description:
** all prototypes
*/

#include <stdbool.h>

#ifndef MY_H
#define MY_H

#define READ_SIZE 10

int my_putchar(char c);
int my_put_error_str(char const *str);
int my_put_nbr(int nb);
char *my_nbr_get_str(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isalphanum(char const *str);
bool my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char **my_str_to_array(char const *str, char const *c_list, bool kp_splts);
char **my_str_to_func_array(char const *str,
                        bool (*is_split_char)(char const c),
                        bool keep_splits);
char *my_strdup(char const *src);
char *my_strndup(char const *src, int n);
char *my_convert_base(char const *nbr, int base1, int base2);
char *get_next_line(int fd);
char *my_strdupcat(int argc, ...);
int my_sort_word_array(char **tab);

#endif