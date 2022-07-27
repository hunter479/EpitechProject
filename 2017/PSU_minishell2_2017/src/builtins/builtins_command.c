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
#include "struct.h"
#include "proto.h"

int	command_cd(char **s, sh_t *sh)
{
	char	*path = s[1];
	char	**tmp = NULL;

	if (!path || path[0] == '\0' || path[0] == '~')
		path = NULL;
	my_cd(path, sh);
	clean_tab(s);
	if (tmp) {
		sh->env = my_tab_dup(tmp);
		clean_tab(tmp);
		return (0);
	}
	return (1);
}

int	command_unsetenv(char **s, sh_t *sh)
{
	char	**tmp = NULL;

	if (!s)
		return (1);
	if (s[1] == NULL) {
		my_putstr_rr("unsetenv: Not enough arguments.\n");
		return (1);
	}
	tmp = my_unsetenv(s, sh);
	clean_tab(s);
	if (tmp) {
		sh->env = my_tab_dup(tmp);
		clean_tab(tmp);
		return (0);
	}
	return (1);
}

int	command_setenv(char **s, sh_t *sh)
{
	char	*name = s[1];
	char	*value = s[2];
	char	**tmp = NULL;
	int	a = size_tab(s);

	if (a == 1) {
		command_env(s, sh);
		return (0);
	}
	if (check_setenv_cond(name, a) == 1) {
		return (1);
	}
	tmp = my_setenv(name, value, sh);
	clean_tab(s);
	if (tmp) {
		sh->env = my_tab_dup(tmp);
		clean_tab(tmp);
		return (0);
	}
	return (-1);
}

int	command_env(char **s, sh_t *sh)
{
	if (sh->env) {
		print_tab(sh->env);
		clean_tab(s);
		return (0);
	}
	return (-1);
}