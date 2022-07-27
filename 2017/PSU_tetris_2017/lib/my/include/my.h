/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** prototype of all function from the lib
*/

#ifndef MY_H_
#define MY_H_

int	my_strcmp(char const *, char const *);
int	my_strncmp(char const *, char const *, int);
int	my_printf(char *, ...);
int	my_putchar(char);
int	my_strlen(char const *);
char	*my_strdup(char *);
char	*my_strcpy(char *, char const *);
char	*dest_add_src(char *, char *);
int	my_putstr(char const *);
char	*my_nb_base(int , char const *);
void	*my_memset(void *, int, int);
int	my_getnbr(char const *);
int	my_put_nbr(int);
int	nega_or_not_nega(int *);
int	sizeof_nbr(int);
char	*int_to_charstr(int);
int	isnum(char);
char	*transfer(int *, char *, int *);
int	indexation(char, char *);
int	type_detect(char, void *, char *);
char	*char_to_str(char);
char	*get_next_line(int);


#endif /* !MY_H_ */
