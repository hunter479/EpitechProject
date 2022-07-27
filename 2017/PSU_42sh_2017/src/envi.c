/*
** EPITECH PROJECT, 2018
** env
** File description:
** smae
*/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

char	**dupenv(char **env)
{
	int	nb = 0;
	int	i = 0;
	char	**ret;

	for (nb = 0; env[nb] != NULL; nb ++);
	ret = malloc(sizeof(char *) * (nb + 1));
	for (i = 0; env[i] != NULL; i ++)
		ret[i] = my_strdup(env[i]);
	ret[i] = NULL;
	return (ret);
}

int	replace_env(mysh_t *ms, char *before, char *after, int a)
{
	ms->env[a] = my_strcatenv(before, after);
	return (0);
}

char	**addenv(mysh_t *ms, char *before, char *after)
{
	int	a = 0;
	char	**ret;

	for (a = 0; ms->env[a] != NULL; a ++);
	ret = malloc(sizeof(char *) * (a + 2));
	for (a = 0; ms->env[a] != NULL; a ++)
		ret[a] = my_strdup(ms->env[a]);
	ret[a] = my_strcatenv(before, after);
	ret[a + 1] = NULL;
	return (ret);
}

int	find_path(mysh_t *ms, char *to_find)
{
	for (int a = 0; ms->env[a] != NULL; a ++) {
		if (my_strcmpath(ms->env[a], to_find) == 0)
			return (a);
	}
	return (-1);
}

void	disp_env(mysh_t *ms)
{
	for (int a = 0; ms->env[a] != NULL; a ++) {
		my_putstr(ms->env[a]);
		my_putchar('\n');
	}
}
