/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** function to save variation
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "minishell.h"

char	*to_equal(char *s)
{
	char	*tmp = s;

	while (tmp[0] != '\0' && tmp[0] != '=') {
		tmp++;
	}
	if (tmp[0] == '=')
		s++;
	return (s);
}

char	*save_one_var(char **env, char *name, char *backup)
{
	int	a = existing_name(name, env);
	int	b = 0;
	int	i = 0;
	char	*tmp = NULL;

	while (env[a] && env[a][b] != '\0' && env[a][b - 1] != '=')
		b++;
	if (env[a] == NULL)
		return (backup);
	tmp = malloc(sizeof(tmp) * (my_strlen(env[a]) - b));
	if (!tmp)
		return (NULL);
	while (env[a][b] != '\0') {
		tmp[i] = env[a][b];
		i++;
		b++;
	}
	tmp[b] = '\0';
	return (tmp);
}

void	save_var(sh_t *sh, char **env)
{
	sh->pwd = save_one_var(env, "PWD", (*sh).pwd);
	sh->path = save_one_var(env, "PATH", (*sh).path);
	sh->home = save_one_var(env, "HOME", (*sh).home);
}
