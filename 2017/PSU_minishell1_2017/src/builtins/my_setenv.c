/*
** EPITECH PROJECT, 2018
** minishell 1
** File description:
** command_setenv
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
#include "my.h"

char	**my_setenv(char *name, char *value, sh_t *sh)
{
	char	**tmp = sh->env;
	int	size = (my_strlen(name) + 2);
	int	a = existing_name(name, sh->env);
	int	x = -1;
	int	j = -1;

	if (value)
		size += my_strlen(value);
	tmp[a] = malloc(sizeof(char) * size + 2);
	if (!tmp[a])
		return (NULL);
	while (name[++x] != '\0')
		tmp[a][x] = name[x];
	tmp[a][x ++] = '=';
	while (value && value[++j] != '\0') {
		tmp[a][x] = value[j];
		x++;
	}
	tmp[a][x] = '\0';
	return (tmp);
}

char	*get_name(char *str)
{
	char	*to_ret = NULL;
	int	a = 0;

	while (str[a] != '\0' && str[a] != '=')
		a++;
	to_ret = malloc(sizeof(char) * (a + 1));
	if (!to_ret)
		return (NULL);
	a = 0;
	while (str[a] != '\0' && str[a] != '=') {
		to_ret[a] = str[a];
		a++;
	}
	to_ret[a] = '\0';
	return (to_ret);
}

int	existing_name(char *name, char **env)
{
	int	a = 0;
	char	*tmp = NULL;

	while (env[a]) {
		tmp = get_name(env[a]);
		if (my_strcmp(tmp, name) == 0) {
			free(tmp);
			return (a);
		}
		a++;
		if (tmp)
			free(tmp);
	}
	return (a);
}