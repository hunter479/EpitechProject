/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** fonction from the lib
*/

#ifndef MY_H_
#define MY_H_

/* error_print */
void	my_putchar_rr(char);
void	my_putstr_rr(char *);

/* Compare */
int	my_strcmp(char const *, char const *);
int	my_strncmp(char const *, char const *, int);
int	indexation(char, char *);
int	isnum(char);
int	nega_or_not_nega(int *);
int	type_detect(char, void *, char *);

/* Display */
int	my_printf(char *, ...);
int	my_putchar(char);
int	my_putstr(char const *);
int	my_put_nbr(int);

/* Count */
int	my_strlen(char const *);

/* Copy */
char	*my_strdup(char *);
char	*my_strcpy(char *, char const *);

/* Convert */
char	*dest_add_src(char *, char *);
char	*my_nb_base(int , char const *);
char	*int_to_charstr(int);
char	*char_to_str(char);
void	*my_memset(void *, int, int);

/* Get */
void	*my_malloc(void *, int);
int	my_getnbr(char const *);
int	sizeof_nbr(int);
char	*get_next_line(int);


#endif /* !MY_H_ */
