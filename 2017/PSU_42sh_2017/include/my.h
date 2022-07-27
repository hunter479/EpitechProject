/*
** EPITECH PROJECT, 2018
** lem_in
** File description:
** Stop mettre des coms a la con par contre :)
*/

#include <sys/types.h>

#ifndef MY_H_
#define MY_H_

typedef	struct	s_keys
{
	char	*up_arrow;
	char	*down_arrow;
	char	*right_arrow;
	char	*left_arrow;
}	keys_t;

typedef struct	s_mysh
{
	pid_t	pid;
	keys_t	keys;
	int	end;
	int	ret;
	char	*s;
	char	*cat;
	char	*exe;
	char	*pexe;
	char	*file;
	char	*old_pwd;
	char	*patha;
	char	**alias;
	char	**com;
	char	**mnv;
	char	**arg;
	char	**red;
	char	**env;
	char	**his;
}	mysh_t;

typedef struct	s_builtins
{
	void	(*builtins)(mysh_t *);
}	bt_t;

typedef	struct	s_andor
{
	char	**com;
	int	sep;
	struct	s_andor	*next;
}	andor_t;

typedef struct	s_hisflag
{
	int	c;
	int	h;
	int	r;
	int	nb;
}	hisflag_t;

typedef	struct	s_cursor
{
	int	x;
	int	y;
	char	*buf;
}	cursor_t;

int	init_term(char **);
char	*int_to_str(int);
char	*getch_line(mysh_t *, char **);
char	**add_in_tab(char **, char *);
int	size_tab(char **);
int	reset_term(char **);
int	my_strncmp(char const *, char const *, int);
int	replace_env(mysh_t *, char *, char *, int);
int	my_strcmpath(char const *, char const *);
void	my_put_inlistf(char **, int, andor_t **);
void	my_put_inlistl(char **, int, andor_t **);
bt_t    *init_values(mysh_t *, char **, bt_t *);
void	wrong_direction(mysh_t *, char *, int);
int	my_strcmp(char const *, char const *);
char	**isthere_another(mysh_t *, char **);
int	do_right(mysh_t *, bt_t *, int, int);
void	have_andor(andor_t **, char **);
int	do_left(mysh_t *, bt_t *, int, int);
int	do_exec_zero(mysh_t *, bt_t *, int);
int	wrong_redir(mysh_t *, char *, int);
char    **addenv(mysh_t *, char *, char *);
int	command(mysh_t *, bt_t *, char *);
int	wrong_pipe(mysh_t *, char *, int);
int	argccess_return(mysh_t *, char *);
int	transform_right(mysh_t *, bt_t *);
char	**my_str_to_wordtab(char *, char);
int	transform_pipe(mysh_t *, bt_t *);
char	**add_str_totab(char **, char *);
int	transform_left(mysh_t *, bt_t *);
char	*my_strcpy(char *, char const *);
char	**before_strtab(char **, char *);
int	analyse_andoret(andor_t *, int);
int	check_invalid(mysh_t *, char *);
char	**after_strtab(char **, char *);
char	**before_septab(char **, char);
int	simple_ordouble(char **, char);
int	do_exec(mysh_t *, bt_t *, int);
int	do_pipe(mysh_t *, bt_t *, int);
int	send_command(mysh_t *, bt_t *);
int	analyze_com(mysh_t *, bt_t *);
int	before_exec(mysh_t *, bt_t *);
char	*my_strcatenv(char *, char *);
char	**after_septab(char **, char);
char    **transform_piredic(mysh_t *);
char	**arg_woutred(char **, char);
int     parse_line(mysh_t *, bt_t *);
void    set_oldpwd(mysh_t *, char *);
void	built_env(mysh_t *, char **);
char	**tab_cat(char **, char **);
int     find_path(mysh_t *, char *);
char	*my_wstrcat(char *, char *);
char	**re_direct(mysh_t *, char);
int     good_redirect(char *, int);
char    **delete_env(char **, int);
char	*my_strcat(char *, char *);
int     no_multi(mysh_t *, char *);
int	analyze(mysh_t *, bt_t *);
void	free_struct(mysh_t, bt_t *);
void    the_setenv(int, mysh_t *);
char	*find_file(char **, char);
void    the_cd(mysh_t *, char *);
int     ambigo(mysh_t *, char *);
int	my_strlent(char *, char);
int     check_argccess(mysh_t *);
int	argccess_slash(mysh_t *);
int     pipe_nredirect(mysh_t *);
char	**environnement(char **);
char	*clear_str(char *, int);
int	my_rprintf(char *, ...);
int	my_putstr(char const *);
int	my_strlen(char const *);
int	my_getnbr(char const *);
int     er_putstr(char const *);
char	**tab_dup(char **, int);
int	countword(char *, char);
int	check_pgs(char *, int);
int	my_printf(char *, ...);
int     check_access(mysh_t *);
void    the_unsetenv(mysh_t *);
int	double_right(mysh_t *);
int	simple_right(mysh_t *);
int	isthere_apip(mysh_t *);
char    *space_between(char *);
void	my_unsetenv(mysh_t *);
int	check_other(mysh_t *);
int	double_left(mysh_t *);
int	simple_left(mysh_t *);
int	check_errno(mysh_t *);
int	cpy_pgs(char *, int);
int     status_handling(int);
char	*get_next_line(int);
int     good_format(char *);
int     exec_pipe(mysh_t *);
void	my_setenv(mysh_t *);
char	**re_pipe(mysh_t *);
void	clean_display(int);
char	*my_strdup(char *);
void    disp_env(mysh_t *);
int     do_piped(mysh_t *);
void    the_exit(mysh_t *);
char	**add_pwd(char **);
int	init_term(char **);
void    error_msg(char *);
int     size_tab(char **);
void	free_tab(char **);
char    **dupenv(char **);
void	my_exit(mysh_t *);
void	my_env(mysh_t *);
char    *cd_void(char *);
int	my_putchar(char);
int	isalphanum(char);
int     er_putchar(char);
void	my_echo(mysh_t *);
int	my_put_nbr(int);
void	my_cd(mysh_t *);
int	is_alpha(char);
int     pigrsp(char);
int	isnum(char);
char	*get_time(void);
char	**set_history(char **, char *);
char	*set_hismember(mysh_t);
int	tablen(char **);
void	my_history(mysh_t *);
char	**rev_tab(char **);
hisflag_t	init_hisflags(hisflag_t);
void	free_list(andor_t *);
void    free_loop(mysh_t);

int	left_or_right(int, int *, cursor_t *);
int	is_arrow(mysh_t *, char, cursor_t *, int *);
char	*only_com(char *);
void	action(char *);
void	history_action(mysh_t *, cursor_t *, int *);
int	history_key(mysh_t *, int, cursor_t *, int *);
void	delete_char(cursor_t *, int *);
char	*getch_it(mysh_t *);
char	*getch_line(mysh_t *, char **);
void	getch_write(cursor_t *, int *, int);

/*	alias	*/

int	straliascmp(char const *, char const *);
int	alias_error(int);
char	**take_map(char *);
char	**get_alias(char *);
char	*verifalias(char *, char **);
void	my_alias(mysh_t *);
void	my_unalias(mysh_t *);
void	my_alias_saver(mysh_t *);
int     find_alias(mysh_t *, char *);

#endif /* MY_H_ */
