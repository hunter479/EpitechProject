/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** prototype of function from the lib
*/

#ifndef MY_H_
	#define MY_H_

void	my_putchar(char);
int	my_putstr(char const *);
int	my_printf(char *, ...);
char	**prep(char *, matrix_t *);
int	found_sq(char **, matrix_t *, int *, int);
void	draw_it(matrix_t, char **);
char	**transfer_(char *);
int	nbr_of_y(char *);
int	nbr_of_x(char *);

#endif /* !MY_H_ */
