/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** list of function to free
*/

#include <stdlib.h>
#include "struct.h"

void	free_tab(char **tab)
{
	int	a = 0;

	while (tab && tab[a]) {
		free(tab[a]);
		a++;
	}
	if (tab)
		free(tab);
}

void	free_list(tetri_t *it)
{
	while (it) {
		if (it->form)
			free_tab(it->form);
		if (it->name)
			free(it->name);
		it = it->next;
	}
}