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

char	**realloc_tab(char **tab, char *s)
{
	int	i = 0;
	char	**tmp = malloc(sizeof(char *) * (size_tab(tab) + 2));

	for (i = 0; tab[i] != NULL; i ++)
		tmp[i] = my_strdup(tab[i]);
	tmp[i] = my_strdup(s);
	tmp[i + 1] = NULL;
	return (tmp);
}

char	**add_str_totab(char **tab, char *s)
{
	if (tab == NULL) {
		tab = malloc(sizeof(char *) * 2);
		tab[0] = my_strdup(s);
		tab[1] = NULL;
		return (tab);
	}
	else
		return (realloc_tab(tab, s));
}

int	find_alias(mysh_t *ms, char *to_find)
{
	if (ms->alias == NULL)
		return (-1);
	for (int a = 0; ms->alias[a] != NULL; a ++) {
		if (my_strcmpath(ms->alias[a] + 6, to_find) == 0)
			return (a);
	}
	return (-1);
}