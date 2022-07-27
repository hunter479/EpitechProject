/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** core_shell
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "proto.h"
#include "struct.h"
#include "my.h"

int	builtins(char **cmd, sh_t *sh, builtins_t *bt)
{
	int	a = 0;
	int	myfd = 0;

	if (!cmd)
		return (1);
	if (my_strcmp(cmd[0], "exit") == 0)
		my_exit(cmd, sh, bt);
	while (my_strcmp(cmd[0], bt[a].cmd) != 0 && a < 5)
		a++;
	if (bt[a].cmd == NULL)
		return (0);
	else {
		myfd = dup(1);
		dup2(sh->oldfd, 1);
		sh->status = bt[a].bt(cmd, sh);
		close(sh->oldfd);
		dup2(myfd, 1);
		dup2(myfd, sh->oldfd);
	}
	return (1);
}

void	simple_cmd(char **cmd, sh_t *sh, builtins_t *bt)
{
	if (builtins(cmd, sh, bt) == 0)
		sh->status = my_execve(cmd, sh, 0);
}

int	recup_command(char **tab, sh_t *sh, builtins_t *bt)
{
	int	a = 0;

	for (; tab[a] && detect_redir(tab[a]) == -1; a++);
	if (tab[a] == NULL) {
		simple_cmd(tab, sh, bt);
		return (0);
	}
	cmd_list(tab, sh, bt);
	if (sh->oldfd == -1)
		return (1);
	return (0);
}

void	instuction_entrer(sh_t *sh, builtins_t *bt)
{
	inst_t	*tab = NULL;
	char	**tmp = NULL;

	if (!sh->cmd || sh->cmd[0] == '\0')
		return;
	tab = put_inst(sh->cmd, tab);
	while (tab) {
		tmp = str_to_tab(tab->str);
		if (cmd_validity(tmp) == 1){;}
		else
			recup_command(tmp, sh, bt);
		wait(NULL);
		tab = tab->next;
	}
	free_list(tab);
	return;
}

void	loop(sh_t sh)
{
	builtins_t	*bt = NULL;
	char	*s = NULL;

	bt = init_built();
	sh.home = save_var("HOME", sh.env, sh.home);
	while (1) {
		my_shell_printing(1);
		s = get_next_line(0);
		sh.cmd = s;
		if (s) {
			sh.cmd = clean_str(s);
			instuction_entrer(&sh, bt);
		}
		if (!s)
			my_exit(NULL, &sh, bt);
		wait(NULL);
	}
}
