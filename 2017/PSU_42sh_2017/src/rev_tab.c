/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** rev_tab
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

char	**rev_tab(char **tab)
{
	int	j = tablen(tab) - 1;
	int	i = 0;
	char	**to_re = malloc(sizeof(char *) * (tablen(tab) + 1));

	while (j >= 0) {
		to_re[i] = my_strdup(tab[j]);
		i++;
		j--;
	}
	tab[i] = NULL;
	return (to_re);
}
