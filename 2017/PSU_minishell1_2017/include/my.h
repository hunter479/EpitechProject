/*
** EPITECH PROJECT, 2018
** my_.h
** File description:
** proto function
*/

#ifndef MY_H_
#define MY_H_

#include "minishell.h"

char	**str_to_tab(char *);
int	my_strcmp(char const *, char const *);
int	my_printf(char *, ...);
void	*my_memset(void *, int, int);
int	my_strlen(char *);
char	*my_strcpy(char *, char const *);
char	**my_tab_dup(char **);
int	size_tab(char **);
char	*my_strdup(char *);
char	*my_strset(char	*str);
char	*my_concate_str(char *dest, char *src);
int	my_strncmp(char const *, char const *, int);
int	my_putchar(char);
void	my_shell_printing(int);
int	isnum(char);


/* save_var */
void	save_var(sh_t *, char **);

/* Print tab */
void	print_tab(char **);

/* SIG */
void	my_sig(void);

/* GNL */
char	*get_next_line(int);

/* EXECVE */
void	my_execve(char	*, sh_t *);

/* EXIT */
void	my_exit(char *, char **, sh_t *);

/* CD */
void	command_cd(char **, sh_t *);
void	my_cd(char *, sh_t *);

/* ENV */
void	command_env(char **, char **);
char	**my_setenv(char *, char *, sh_t *);

/* SETENV */
void	command_setenv(char **, sh_t *);
int	check_setenv(char *);
char	*get_name(char *);
int	check_setenv(char *);
int	existing_name(char *, char **);

/* UNSETENV */
void	command_unsetenv(char **, sh_t *);
char	**my_unsetenv(char **, sh_t *);

/* CLEANING */
void	clean_in_struct(sh_t *);
char	*clean_set(char *);
char	*clean_str(char *);
void	clean_tab(char **);

#endif /* !MY_H_ */