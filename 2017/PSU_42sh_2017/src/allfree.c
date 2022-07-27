/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** free
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

void	free_tab(char **tab)
{
	if (!tab)
		return;
	for (int i = 0; tab[i] != NULL; i ++)
		free(tab[i]);
	free(tab);
}

void	free_list(andor_t *list)
{
	andor_t	*tmp;

	while (list != NULL) {
		tmp = list;
		free_tab(list->com);
		list = list->next;
		free(tmp);
	}
	free(list);
}

void    free_loop(mysh_t ms)
{
	if (ms.s)
		free(ms.s);
	if (ms.mnv != NULL)
		free_tab(ms.mnv);
}

void	free_struct(mysh_t ms, bt_t *bt)
{
	free(bt);
	free_tab(ms.env);
	free_tab(ms.his);
}
