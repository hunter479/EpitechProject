/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** prototype of all function from the lib
*/

#ifndef MY_H_
#define MY_H_

typedef struct	s_link
{
	char		*token;
	struct s_link	*next;
}	link_t;

/* functions */

int	my_strcmp(char const *, char const *);
int	my_strncmp(char const *, char const *, int);
int	my_printf(char *, ...);
int	my_rprintf(char *, ...);
int	my_putchar(char);
int	my_strlen(char const *);
int	my_putstr(char const *);
int	my_getnbr(char const *);
int	my_put_nbr(int);
int	nega_or_not_nega(int *);
int	sizeof_nbr(int);
int	isnum(char);
int	indexation(char, char *);
int	type_detect(char, void *, char *);

void	*my_memset(void *, int, int);
void	my_str_cpy(char *, char *, int);

char	*my_nb_base(int , char const *);
char	*my_strcpy(char *, char const *);
char	*dest_add_src(char *, char *);
char	*int_to_charstr(int);
char	*transfer(int *, char *, int *);
char	*my_strdup(char *);
char	*char_to_str(char);
char	*get_next_line(int);

char	*my_wstrcat(char *, char *);
char	*my_strcatenv(char *, char *);
int	my_strcmppath(char const *, char const *);
char	*clear_str(char *);
int	countword(char *, char);
int	my_strlent(char *, char);
char	**my_str_to_wordtab(char *, char);
#endif /* !MY_H_ */
