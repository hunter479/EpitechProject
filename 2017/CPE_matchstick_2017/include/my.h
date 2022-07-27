/*
** EPITECH PROJECT, 2017
** matchsitck
** File description:
** prototypage de function
*/

#ifndef MY_H_
	#define MY_H_

#include "matchstick.h"

/* IA */
char	**ia(nb_t *, char **);

/* Cleaning */
void	clean_tab(char **);

/* lib */
int	my_strlen(char const *);
int	my_getnbr(char const *);
void	*my_memset(void *, int, int);
int	my_printf(char *, ...);

/* verif and check */
int	is_number(char *);
int	tab_stick(char **);

/* Game */
int	start(char **, nb_t *);

/* Matches and Line */
int	line_box(nb_t *, char **);
int	matches_box(nb_t *, int, char **);
int	there_is_stick(int, char **);
char	**undo_stick(char **, int, int);

/* Winner */
void	is_winner(nb_t *, char **);

/* printing */
void	print_tab(char **);

/* get_next_line */
char	*get_next_line(int);

/* Make Sqare */
char	**prep_tab(nb_t *);

#endif /* !MY_H_ */
