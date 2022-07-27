/*
** EPITECH PROJECT, 2018
** n4s
** File description:
** n4s
*/

#ifndef N4S_H_
# define N4S_H_

#include "struct.h"

void	my_putstr(char *);
void	get_clear(char *);
void	turn_left(val_t *);
void	turn_right(val_t *);
void	send_cmd(char *, int);
void	start_and_move(char *);
void	left_or_right(val_t *);
void	get_right_value(val_t *, char *);
int	move_straight(val_t *);
int	nbrlen(int);
void	is_ok(char *);

int	count_colons(char *);
int	get_top_value(val_t *, char *);
int	get_left_value(val_t *, char *);

int	nbrlen(int);
int	my_strlen(char *);
int	my_printf(char *, ...);

char	*int_to_char(int);
char	*my_revstr(char *);
char	*get_next_line(int);
char	*rotate_and_move(double, double);

#endif /* !N4S_H_ */
