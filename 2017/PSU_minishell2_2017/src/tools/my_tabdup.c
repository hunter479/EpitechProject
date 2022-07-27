/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** copy a char **
*/

#include <stdlib.h>
#include "proto.h"
#include "struct.h"
#include "my.h"

int	size_tab(char **tab)
{
	int	a = 0;

	while (tab && tab[a] != NULL)
		a++;
	return (a);
}

char	**my_tab_dup(char **tab)
{
	char	**tmp = NULL;
	int	a = 0;

	tmp = my_malloc(tmp, (size_tab(tab) + 2));
	if (!tmp)
		return (NULL);
	while (tab[a] != NULL) {
		tmp[a] = my_strdup(tab[a]);
		a++;
	}
	tmp[a] = NULL;
	tmp[++a] = NULL;
	return (tmp);
}