/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** and or
*/

#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

int	analyse_andoret(andor_t *andor, int ret)
{
	if (andor->sep == 2) {
		if (ret == 1)
			return (0);
		else
			return (1);
	}
	else {
		if (ret == 1)
			return (1);
		else
			return (0);
	}
}

void	have_andor(andor_t **andor, char **tab)
{
	char	**tmp;

	for (int i = 0; tab[i] != NULL; i ++) {
		if (my_strcmp(tab[i], "&&") == 0) {
			tmp = before_strtab(tab, "&&");
			my_put_inlistl(tmp, 1, andor);
			return (have_andor(andor, after_strtab(tab, "&&")));
		}
		if (my_strcmp(tab[i], "||") == 0) {
			tmp = before_strtab(tab, "||");
			my_put_inlistl(tmp, 2, andor);
			return (have_andor(andor, after_strtab(tab, "||")));
		}
	}
	my_put_inlistl(tab, 0, andor);
	free_tab(tab);
	return;
}