/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** add pwd
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

char	**arg_woutred(char **tab, char sep)
{
	int	i = 0;
	int	j = 0;
	int	mal = size_tab(tab);
	char	**ret;

	ret = malloc(sizeof(char *) * (mal + 1));
	for (i = 0; *tab[i] != sep && tab[i] != NULL; i ++)
		ret[i] = my_strdup(tab[i]);
	for (j = i, i += 2; tab[i] != NULL; j ++, i ++)
		ret[j] = my_strdup(tab[i]);
	ret[j] = NULL;
	return (ret);
}

char	**tab_cat(char **tab1, char **tab2)
{
	int	size;
	char	**tmp;
	int	i = 0;
	int	k = 0;

	size = (size_tab(tab1) + size_tab(tab2) + 1);
	tmp = malloc(sizeof(char *) * size);
	for (i = 0; tab1[i] != NULL; k ++, i ++)
		tmp[k] = my_strdup(tab1[i]);
	for (i = 0; tab2[i] != NULL; k ++, i ++)
		tmp[k] = my_strdup(tab2[i]);
	tmp[k] = NULL;
	return (tmp);
}

char	**tab_dup(char **src, int k)
{
	char	**tmp;
	int	i = 0;
	int	j = 0;
	int	mal = size_tab(src);

	tmp = malloc(sizeof(char *) * (mal + 1 - k));
	for (i = k; src[i] != NULL; i ++)
		tmp[j++] = my_strdup(src[i]);
	tmp[j] = NULL;
	return (tmp);
}

char	**delete_env(char **env, int a)
{
	int	mal = 0;
	int	i = 0;
	char	**ret;

	for (mal = 0; env[mal] != NULL; mal ++);
	ret = malloc(sizeof(char *) * mal);
	for (mal = 0, i = 0; env[mal] != NULL; mal ++, i ++) {
		if (mal == a)
			i --;
		else
			ret[i] = my_strdup(env[mal]);
	}
	ret[i] = NULL;
	return (ret);
}

char	**add_pwd(char **tab)
{
	char	*pwd = getcwd(NULL, 0);
	char	**tmp;
	int	i = 0;

	for (i = 0; tab[i] != NULL; i ++);
	tmp = malloc(sizeof(char *) * (i + 2));
	for (i = 0; tab[i] != NULL; i ++)
		tmp[i] = my_strdup(tab[i]);
	tmp[i] = my_strdup(pwd);
	tmp[i + 1] = NULL;
	free(pwd);
	return (tmp);
}
