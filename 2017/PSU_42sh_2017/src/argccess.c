/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** access
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

int	argccess_return(mysh_t *ms, char *acc)
{
	int	b = 0;
	int	a = 0;

	for (int i = 0; ms->arg[0][i] != '\0'; i ++)
		b += (ms->arg[0][i] == '/') ? 1 : 0;
	if (b >= 1) {
		a = access(acc, F_OK | X_OK);
		if (a != 0) {
			free(acc);
			return (1);
		}
		else {
			ms->exe = my_strdup(acc);
			free(acc);
			return (2);
		}
	}
	free(acc);
	return (0);
}

int	argccess_slash(mysh_t *ms)
{
	char	*get = getcwd(NULL, 0);
	char	*acc = my_wstrcat(get, ms->arg[0]);

	free(get);
	if (*ms->arg[0] == '/' ||
	(*ms->arg[0] == '.' && ms->arg[0][1] == '/')) {
		if (access(ms->arg[0], F_OK) != 0)
			return (1);
		else {
			ms->exe = my_strdup(ms->arg[0]);
			return (2);
		}
	}
	else
		return (argccess_return(ms, acc));
}

int	check_argtinue(mysh_t *ms)
{
	int	i = 0;

	while (ms->mnv[i] != NULL) {
		ms->cat = my_wstrcat(ms->mnv[i], ms->arg[0]);
		if (access(ms->cat, F_OK | X_OK) != 0)
			i += 1;
		else {
			ms->exe = my_strdup(ms->cat);
			free(ms->cat);
			return (ms->ret = 0);
		}
		free(ms->cat);
	}
	if (ms->mnv[i] == NULL) {
		my_rprintf("%r: Command not found.\n", ms->arg[0]);
		return (ms->ret = 1);
	}
	return (ms->ret = 0);
}

int	check_argccess(mysh_t *ms)
{
	int	ret = 0;

	if (ms->arg[0] == NULL)
		return (1);
	ret = argccess_slash(ms);
	if (ret == 2)
		return (ms->ret = 0);
	if (ms->mnv == NULL || ret == 1) {
		my_rprintf("%r: Command not found.\n", ms->arg[0]);
		return (ms->ret = 1);
	}
	else
		return (check_argtinue(ms));
}