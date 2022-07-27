/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** proto function
*/

#ifndef PROTO_H_
#define PROTO_H_

#include "struct.h"

void	simple_cmd(char **, sh_t *, builtins_t *);

/*
**	BUITINS
*/

int	builtins(char **, sh_t *, builtins_t *);
void	instuction_entrer(sh_t *, builtins_t *);
void	loop(sh_t);

/* cd */
int	command_cd(char **, sh_t *);
char	*to_user(char *, sh_t);
char	*my_concate_str(char *, char *);
void	my_cd(char *, sh_t *);

/* unsetenv */
int	command_unsetenv(char **, sh_t *);
int	in_the_list(char *, char **);
char	**my_unsetenv(char **, sh_t *);

/* setenv */
int	command_setenv(char **, sh_t *);
char	**my_setenv(char *, char *, sh_t *);
char	*get_name(char *);
int	existing_name(char *, char **);
int	check_setenv_cond(char *, int);

/* env */
int	command_env(char **s, sh_t *);
int	check_value(char *s);

/* exit */
int	my_exit(char ** cmd, sh_t *sh, builtins_t *bh);

/*
**	TOOLS
*/

int	first_letter(char);
int	check_setenv(char *);
int	len_to_equal(char *);
int	nb_pipe(char *);
int	nb_redir(char *);

/* clean */
void	clean_tab(char **);
char	*clean_str(char *);
void	free_struct(sh_t *);
void	free_list(inst_t *);
char	*clear_pipe(char *);
char	*clear_redir(char *);
int	skip_to_word(int, char *, int);
void	clean_cmd(cmd_t *);

/* addition */
void	my_shell_printing(int);

/* signals */
void	signal_handling(int);
void	my_sig(void);

/* copy */
int	size_tab(char **tab);
char	**my_tab_dup(char **tab);
char	*save_var(char *, char **, char *);

/* print */
void	print_tab(char **tab);

/* str_word_tab */
char	**str_to_tab(char *);
char	**prep_new_string(char **, int *, int *, char **);
int	nbr_word(char *);
int	size_word(char *);

/*
**	EXECVE
*/

void	file_error(char *);
char	*getpath(char **);
char	**add_pwd(char **);
char	*undo_bin(char *);
char	**prep_path(char *, sh_t *);
int	my_execve(char **, sh_t *, int);
void	cmd_list(char **, sh_t *, builtins_t *);
int	my_errno(void);

/*
**	CORE
*/

/* Manipulation */
char	**add_in_tab(char **, char *);
char	**concate_tab(char **, char **);

/* Count */
int	inst_len(char *);
int	nb_instruct(char *);

/* Redir */
int	cmd_validity(char **);
int	check_recurrence_redir(int *, char **);
int	check_missing_redir(int *, char **);
int	msg_redir(int *, int);
int	tab_redir(char *);
char	**get_cmd1(char **, int);
char	**get_cmd2(char **, int);
char	*get_redir(char **, int);
int	detect_redir(char *);
void	get_tab_args(char **, char ***, sh_t *);
int	check_redir(int *, char **);
void	is_cmd_found(char **, char **, int);
int	*tab_pos_red(char **);
int	analyse_status(int);
int	do_pipe(cmd_t *, sh_t *, builtins_t *);

/* init */
builtins_t	*init_built(void);

/*
**	Linked_list_struct
*/
char	**str_to_tab_list(char *);
inst_t	*put_inst(char *, inst_t *);
void	put_in_list(char *, inst_t **);

#endif /* !PROTO_H_ */