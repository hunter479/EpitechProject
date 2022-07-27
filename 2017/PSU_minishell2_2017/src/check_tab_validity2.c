/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** check_tab_validity2
*/

#include <unistd.h>
#include "my.h"
#include "proto.h"

int	check_missing_redir(int *list, char **tab)
{
	int	a = 0;

	for (; list[a] != -1; a++);
	if (a > 0)
		a--;
	while (a > -1) {
		if (tab_redir(tab[list[a] + 1]) == 1)
			return (msg_redir(list, 1));
		a--;
	}
	return (0);
}

int	check_redir(int *list, char **tab)
{
	int	a = 0;

	for (; list[a] != -1; a++);
	if (a > 0)
		a--;
	while (a > -1) {
		if (tab_redir(tab[list[a] + 1]) == -1)
			return (msg_redir(list, 2));
		a--;
	}
	return (0);
}

int	one_way(int here, int one_step, int *list)
{
	if (here == 1 || here == 3)
		if (one_step == 2 || one_step == 4 || one_step == 5
			|| one_step == 1 || one_step == 3)
			return (msg_redir(list, 3));
	if (here == 2 || here == 4)
		if (one_step == 1 || one_step == 3 || one_step == 5
			|| one_step == 2 || one_step == 4)
			return (msg_redir(list, 3));
	return (0);
}

int	check_redir_pipe(int here, int one_step, int *list)
{
	if (here == 5)
		if (one_step == 2 || one_step == 4)
			return (msg_redir(list, 3));
	return (0);
}

int	check_recurrence_redir(int *list, char **tab)
{
	int	a = 0;
	int	here = 0;
	int	one_step = 0;

	while (list[a] != -1) {
		here = detect_redir(tab[list[a]]);
		if (list[a + 1] == -1)
			return (0);
		one_step = detect_redir(tab[list[a + 1]]);
		if (one_way(here, one_step, list) == 1)
			return (1);
		if (check_redir_pipe(here, one_step, list) == 1)
			return (1);
		a++;
	}
	return (0);
}