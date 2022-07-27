/*
** EPITECH PROJECT, 2017
** matchstick
** File description:
** function for cleaning
*/

#include "my.h"
#include <stdlib.h>

void	clean_tab(char **tab)
{
	int	a = 0;
	char	**tmp = tab;

	while (tmp[a] != NULL) {
		free(tmp[a]);
		a++;
	}
	free(tmp);
	return;
}