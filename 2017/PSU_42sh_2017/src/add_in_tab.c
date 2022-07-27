/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** add_in_tab
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

void	clean_tab(char **tab)
{
	int	a = 0;
	int	b = size_tab(tab);

	while (a < b) {
		free(tab[a]);
		a++;
	}
	if (tab)
		free(tab);
	return;
}

char	**add_in_tab(char **tab, char *s)
{
	int	a = 0;
	char	**tmp = NULL;

	tmp = malloc(sizeof(char *) * (size_tab(tab) + 2));
	if (!tab) {
		tmp[0] = strdup(s);
		tmp[1] = NULL;
		return (tmp);
	}
	if (!tmp)
		return (NULL);
	while (tab[a]) {
		tmp[a] = strdup(tab[a]);
		a++;
	}
	tmp[a ++] = strdup(s);
	tmp[a] = NULL;
	clean_tab(tab);
	return (tmp);
}