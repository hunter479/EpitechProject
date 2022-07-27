/*
** EPITECH PROJECT, 2018
** dante
** File description:
** list tool
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "my.h"

void	my_put_inlistf(char **tab, int sep, andor_t **andor)
{
	andor_t	*tmp = *andor;
	andor_t	*elem;

	elem = malloc(sizeof(*elem));
	elem->com = tab_dup(tab, 0);
	elem->sep = sep;
	if (tmp == NULL) {
		*andor = elem;
		(*andor)->next = NULL;
		return;
	}
	(elem)->next = tmp;
	*andor = elem;
}

void	my_put_inlistl(char **tab, int sep, andor_t **andor)
{
	andor_t	*tmp = *andor;
	andor_t	*elem;

	elem = malloc(sizeof(*elem));
	elem->com = tab_dup(tab, 0);
	elem->sep = sep;
	if (tmp == NULL) {
		elem->next = NULL;
		*andor = elem;
		return;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	elem->next = NULL;
	tmp->next = elem;
}