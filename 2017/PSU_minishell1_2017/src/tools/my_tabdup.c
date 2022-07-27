/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** copy a char **
*/

#include <stdlib.h>
#include "my.h"

int	size_tab(char **tab)
{
	int	a = 0;

	while (tab[a] != NULL)
		a++;
	return (a);
}

char	**my_tab_dup(char **tab)
{
	char	**tmp = malloc(sizeof(char *) * (size_tab(tab) + 2));
	int	a = 0;

	if (!tmp)
		return (NULL);
	tmp = my_memset(tmp, 0, sizeof(char *) * (size_tab(tab) + 2));
	while (tab[a]) {
		tmp[a] = malloc(sizeof(char) * (my_strlen(tab[a])+ 2));
		if (!tmp[a])
			return (NULL);
		tmp[a] = my_memset(tmp[a], 0, (my_strlen(tab[a]) + 2));
		tmp[a] = my_strcpy(tmp[a], tab[a]);
		a++;
	}
	return (tmp);
}