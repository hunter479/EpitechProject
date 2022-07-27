/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** function unsetenv
*/

#include <stdlib.h>
#include "minishell.h"
#include "my.h"

char	*unsetenv_set_string(char *str)
{
	char	*tmp = malloc(sizeof(char) * (my_strlen(str) + 2));

	if (!tmp)
		return (NULL);
	tmp = my_memset(tmp, 0, (my_strlen(str) + 2));
	tmp = my_strcpy(tmp, str);
	return (tmp);
}

int	in_the_list(char *line_env, char **cmd)
{
	int	a = 1;
	char	*s = NULL;

	if (!line_env)
		return (-1);
	s = get_name(line_env);
	while (cmd[a] != NULL) {
		if (my_strcmp(cmd[a], s) == 0) {
			free(s);
			return (1);
		}
		else
			a++;
	}
	free(s);
	return (0);
}

char	**my_unsetenv(char **cmd, sh_t *sh)
{
	char	**tmp = malloc(sizeof(char *) * (size_tab(sh->env) + 2));
	int	a = 0;
	int	b = 0;
	int	k = 0;

	if (!tmp)
		return (NULL);
	while (sh->env[a]) {
		k = in_the_list(sh->env[a], cmd);
		if (sh->env[a] != NULL && k == 0) {
			tmp[b] = unsetenv_set_string(sh->env[a]);
			a++;
			b++;
		}
		else
			a++;
	}
	tmp[b] = NULL;
	return (tmp);
}