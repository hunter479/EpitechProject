/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** proto of function
*/

#ifndef PROTO_H_
#define PROTO_H_

#include "struct.h"
#include <dirent.h>
#include "nick.h"

/* Flags */
int	flags(int, char **, tetri_t *);

/* print */
void	tetri_print(tetri_t *, keys_t *);
void	key_print(keys_t *);
int	print_arrow(char *);


/* sorting */
void	sort(tetri_t **);

/* tools */
void	*my_malloc(void *, int);
int	tetri_len_line(char *);
int	nb_tetri(tetri_t *);

/* init */
void	init_struct(tetri_t *);
int	init_term(char **);

/* free */
void	free_list(tetri_t *);
void	free_tab(char **);

/* listing */
tetri_t	*stock_info(char *, char *);
void	put_in_list(tetri_t *, tetri_t **);
tetri_t	*get_tetriminos(char *);

/* check */
int	line_is_good(int *, char *, int, tetri_t *);
int	check_first_line(char *);
int	check_tetri(char *);
int	check_line_form(char *);
tetri_t	*error_it(tetri_t *, char *);
int	valid_arg(char *, char **);
char	**tab_arg(void);

/* info */
tetri_t	*get_info(DIR *, char *);
char	*get_name(char *);
int	getsize_x(char *);
int	getsize_y(char *);
int	getcolor(char *);
char	*cpy_nb(char *, char *, int *);
void	recup_info(tetri_t *, char *, char *);
int	recup_form(tetri_t *, char *, int, char *);

/* path and co */
char	*catpath(char *, char *);

#endif /* !PROTO_H_ */
