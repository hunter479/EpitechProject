/*
** EPITECH PROJECT, 2018
** bite
** File description:
** ui
*/

#ifndef NICK_H_
#define NICK_H_

#include "struct.h"

typedef struct	s_keys
{
	int	level;
	char	*left;
	char	*right;
	char	*turn;
	char	*drop;
	char	*quit;
	char	*pause;
	int	row;
	int	col;
	int	next;
	int	debug;
}	keys_t;

typedef struct	s_fl
{
	char	*cmp;
	int	(*flags)(keys_t *, char **, int, int);
}	fl_t;

int	my_putchar(char);
int	my_putstr(char const *);
int	my_put_nbr(int);
int	my_strlen(char const *);
int	my_getnbr(char const *);
int	check_debug_mode(char **av, int j, keys_t *keys);
char	*my_strcpy(char *, char const *);
char	*my_strdup(char *);
char	*stockstr(char *, int);
fl_t	*init_flags(fl_t *);
fl_t	*init_flags2(fl_t *);
int	check_flags(char **, keys_t *, fl_t *, tetri_t *);
int	check_arg(char *, char *);
int	check_opt(char **, int, keys_t *, fl_t *);
int	display_help(char *);
int	display_help2(void);
void	init_keys(keys_t *);
int	change_level(keys_t *, char **, int, int);
int	level_long(keys_t *, char **, int, int);
int	map_size(keys_t *, char **, int, int);
int	without_next(keys_t *, char **, int, int);
int	change_key(keys_t *, char **, int, int);
int	key_change(keys_t *, char **, int, int);
int	change_key2(keys_t *, char **, int, int);
int	key_change2(keys_t *, char *, int);
int	debug_mode(keys_t *, tetri_t *);

#endif /* NICK_H_ */