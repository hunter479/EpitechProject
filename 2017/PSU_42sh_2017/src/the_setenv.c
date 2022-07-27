/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** setenv
*/

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

int	check_setenv(mysh_t *ms)
{
	if (is_alpha(ms->arg[1][0]) != 1) {
		my_printf("%r", ms->arg[0]);
		er_putstr(": Variable name must begin with a letter.\n");
		return (-1);
	}
	for (int i = 0; ms->arg[1][i] != '\0'; i ++)
		if (isalphanum(ms->arg[1][i]) != 1) {
			my_printf("%r", ms->arg[0]);
			er_putstr(": Variable name must contain ");
			er_putstr("alphanumeric characters.\n");
			return (-1);
		}
	return (0);
}

void	set_oldpwd(mysh_t *ms, char *way)
{
	ms->old_pwd = my_strdup(way);
	ms->arg = malloc(sizeof(char *) * 4);
	ms->arg[0] = my_strdup("setenv");
	ms->arg[1] = my_strdup("OLDPWD");
	ms->arg[2] = my_strdup(ms->old_pwd);
	ms->arg[3] = NULL;
	my_setenv(ms);
	free_tab(ms->arg);
}

void	the_setenv(int ac, mysh_t *ms)
{
	int	a = 0;

	if (check_setenv(ms) == 0) {
		a = find_path(ms, ms->arg[1]);
		if (ac == 2)
			ms->arg[2] = "";
		if (a == -1)
			ms->env = addenv(ms, ms->arg[1], ms->arg[2]);
		if (a >= 0)
			ms->ret = replace_env(ms, ms->arg[1], ms->arg[2], a);
		ms->arg[2] = (ac == 2) ? NULL : ms->arg[2];
	}
	else
		ms->ret = 1;
}
