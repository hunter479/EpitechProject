/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** function for execve
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "minishell.h"

char	*getpath(char **env)
{
	int	a = existing_name("PATH", env);
	char	*tmp = NULL;
	int	i = -1;

	if (!env[a]) {
		tmp = my_strdup("/usr/local/bin /usr/bin /bin");
		return (tmp);
	}
	tmp = clean_set(env[a]);
	if (!tmp)
		return (NULL);
	tmp = my_strcpy(tmp, env[a]);
	while (tmp[0] != '=')
		tmp++;
	tmp++;
	while (tmp[++i] != '\0')
		if (tmp[i] == ':')
			tmp[i] = ' ';
	tmp[i] = '\0';
	return (tmp);
}

char	**add_pwd(char **path_tab)
{
	int	a = 0;
	char	*pwd;

	while (path_tab[a])
		a++;
	pwd = getcwd(NULL, 0);
	path_tab[a] = malloc(sizeof(char) * my_strlen(pwd) + 1);
	if (!path_tab[a])
		return (NULL);
	path_tab[a] = my_strcpy(path_tab[a], pwd);
	a++;
	path_tab[a] = NULL;
	return (path_tab);
}

char	*undo_bin(char *s)
{
	int	a = 0;

	if (my_strncmp(s, "/bin/", 5) == 0)
		while (a < 5) {
			s++;
			a++;
		}
	return (s);
}

char	**prep_path(char *s, sh_t *sh)
{
	char	*path_env = getpath(sh->env);
	char	**path_tab = NULL;
	int	a = 0;

	path_tab = str_to_tab(path_env);
	path_tab = add_pwd(path_tab);
	s = undo_bin(s);
	while (path_tab[a] != NULL) {
		path_tab[a] = my_concate_str("/", path_tab[a]);
		path_tab[a] = my_concate_str(s, path_tab[a]);
		a++;
	}
	return (path_tab);
}

void	my_execve(char	*s, sh_t *sh)
{
	char	**args = str_to_tab(s);
	char	**pth = prep_path(args[0], sh);
	int	a = 0;

	if (fork() == 0) {
		while (a < size_tab(pth) && (access(pth[a], F_OK | X_OK) != 0))
			a++;
		if (a == size_tab(pth)) {
			my_printf("%s = command not found\n", args[0]);
			clean_tab(args);
			clean_tab(pth);
			exit(EXIT_FAILURE);
		}
		else if (execve(pth[a], args, sh->env) != -1) {
			clean_tab(args);
			clean_tab(pth);
			exit(EXIT_SUCCESS);
		}
	}
}