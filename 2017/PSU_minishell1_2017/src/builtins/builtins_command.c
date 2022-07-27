/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** build in command for the minishell
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "minishell.h"

void	command_cd(char **s, sh_t *sh)
{
	char	*path = s[1];
	char	**tmp = NULL;

	if (!path || path[0] == '\0' || path[0] == '~')
		path = NULL;
	if (path && my_strcmp(path, "/home") == 0)
		path = NULL;
	if (path && my_strcmp(path, "/home/") == 0)
		path = NULL;
	my_cd(path, sh);
	clean_tab(s);
	if (tmp) {
		sh->env = my_tab_dup(tmp);
		clean_tab(tmp);
	}
}

void	command_unsetenv(char **s, sh_t *sh)
{
	char	**tmp = NULL;

	if (!s)
		return;
	tmp = my_unsetenv(s, sh);
	clean_tab(s);
	if (tmp) {
		sh->env = my_tab_dup(tmp);
		clean_tab(tmp);
	}
}

void	command_setenv(char **s, sh_t *sh)
{
	char	*name = s[1];
	char	*value = s[2];
	char	**tmp = NULL;
	int	a = size_tab(s);

	if (a == 4 || a == 0)
		return;
	if (a == 1) {
		command_env(s, sh->env);
		return;
	}
	if (!name || check_setenv(name) == -1)
		return;
	tmp = my_setenv(name, value, sh);
	clean_tab(s);
	if (tmp) {
		sh->env = my_tab_dup(tmp);
		clean_tab(tmp);
	}
}

void	command_env(char **s, char **env)
{
	print_tab(env);
	clean_tab(s);
	return;
}