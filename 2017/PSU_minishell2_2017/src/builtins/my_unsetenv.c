/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** function unsetenv
*/

#include <stdlib.h>
#include "proto.h"
#include "struct.h"
#include "my.h"

int	in_the_list(char *line_env, char **cmd)
{
	int	a = 1;
	char	*s = NULL;

	if (!line_env)
		return (-1);
	s = get_name(line_env);
	while (s && cmd[a] != NULL) {
		if (my_strcmp(cmd[a], s) == 0) {
			free(s);
			return (1);
		}
		else
			a++;
	}
	if (s)
		free(s);
	return (0);
}

char	**my_unsetenv(char **cmd, sh_t *sh)
{
	char	**tmp = NULL;
	int	a = 0;
	int	b = 0;
	int	k = 0;

	tmp = my_malloc(tmp, size_tab(sh->env) + 2);
	if (!tmp)
		return (NULL);
	while (sh->env[a]) {
		k = in_the_list(sh->env[a], cmd);
		if (sh->env[a] != NULL && k == 0) {
			tmp[b] = my_strdup(sh->env[a]);
			a++;
			b++;
		}
		else
			a++;
	}
	tmp[b] = NULL;
	return (tmp);
}