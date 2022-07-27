/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** prep_exec
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>
#include "proto.h"
#include "struct.h"
#include "my.h"

char	*getpath(char **env)
{
	int	a = existing_name("PATH", env);
	char	*tmp = NULL;
	int	i = -1;

	if (!env[a] || check_value(env[a]) == -1) {
		tmp = my_strdup("");
		return (tmp);
	}
	tmp = env[a];
	while (tmp[0] != '=')
		tmp++;
	tmp++;
	while (tmp[++i] != '\0')
		if (tmp[i] == ':')
			tmp[i] = ' ';
	tmp[i] = '\0';
	while (tmp[0] == ' ' || tmp[0] == '\t')
		tmp++;
	return (tmp);
}

char	**add_pwd(char **path_tab)
{
	int	a = 0;
	char	*pwd;

	if (!path_tab)
		path_tab = my_malloc(path_tab, 1);
	while (path_tab[a])
		a++;
	pwd = getcwd(NULL, 0);
	path_tab[a] = my_strdup(pwd);
	a++;
	path_tab[a] = NULL;
	free(pwd);
	return (path_tab);
}

char	**prep_path(char *s, sh_t *sh)
{
	char	*path_env = getpath(sh->env);
	char	**path_tab = NULL;
	int	a = 0;

	if (s[0] == '/') {
		path_tab = str_to_tab(s);
		return (path_tab);
	}
	if (s[0] != '.') {
		path_tab = str_to_tab(path_env);
		path_tab = add_pwd(path_tab);
	}
	else
		path_tab = add_pwd(path_tab);
	while (path_tab[a] != NULL) {
		path_tab[a] = my_concate_str("/", path_tab[a]);
		path_tab[a] = my_concate_str(s, path_tab[a]);
		a++;
	}
	return (path_tab);
}
