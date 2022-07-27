/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** cleaning tools
*/

#include <stdlib.h>
#include "proto.h"
#include "struct.h"
#include "my.h"

void	free_struct(sh_t *sh)
{
	if (sh->cmd)
		free(sh->cmd);
	if (sh->env)
		clean_tab(sh->env);
	if (sh->home)
		free(sh->home);
	if (sh->oldpwd)
		free(sh->oldpwd);
	return;
}

void	free_list(inst_t *it)
{
	inst_t	*tmp = it;

	while (tmp) {
		free(tmp->str);
		tmp = tmp->next;
	}
	free(it);
	return;
}

void	clean_tab(char **tab)
{
	int	a = 0;
	int	b = size_tab(tab);

	while (a < b) {
		free(tab[a]);
		a++;
	}
	if (tab)
		free(tab);
	return;
}

void	clean_cmd(cmd_t *cmd)
{
	cmd_t	*tmp = cmd;

	if (tmp->cmd1)
		clean_tab(tmp->cmd1);
	if (tmp->cmd2)
		clean_tab(tmp->cmd2);
	if (tmp->redir)
		free(tmp->redir);
	if (tmp)
		free(tmp);
}