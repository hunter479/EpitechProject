/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** struct
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

typedef	struct		s_sh
{
	char	*cmd;
	char	**env;
	int	*list;
	int	newfd;
	int	oldfd;
	char	*home;
	char	*oldpwd;
	int	status;
	pid_t	pid;
}	sh_t;

typedef	struct		s_inst
{
	char	*str;
	struct s_inst *next;
}	inst_t;

typedef	struct		s_command
{
	char	**cmd1;
	char	**cmd2;
	char	*redir;
}	cmd_t;

typedef	struct		s_builtins
{
	char	*cmd;
	int	(*bt)(char **, sh_t *);
}	builtins_t;

#endif /* !MINISHELL_H_ */
