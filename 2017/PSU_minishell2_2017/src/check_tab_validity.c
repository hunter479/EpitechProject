/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** check_tab_validity
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "proto.h"

int	tab_redir(char *s)
{
	char *tab[] = {">", "<", ">>", "<<", "|", NULL};
	int	a = 0;

	if (!s)
		return (-1);
	while (tab[a] && my_strcmp(tab[a], s) != 0)
		a++;
	if (tab[a] == NULL)
		return (0);
	else
		return (1);
}

char	redir(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

int	*tab_pos_red(char **tab)
{
	int	*list_post = (int *)NULL;
	int	a = 0;
	int	ref = 0;

	while (tab[a]) {
		if (redir(tab[a][0]))
			ref++;
		a++;
	}
	list_post = my_malloc(list_post, ref);
	if (!list_post)
		return (NULL);
	a = ref = 0;
	while (list_post && tab[a]) {
		if (redir(tab[a][0]))
			list_post[ref ++] = a;
		a++;
	}
	list_post[ref] = -1;
	return (list_post);
}

int	msg_redir(int *list, int option)
{
	if (option == 1)
		my_putstr_rr("Missing name for redirect.\n");
	else if (option == 2)
		my_putstr_rr("Invalid null command.\n");
	if (option == 3)
		my_putstr_rr("Ambiguous output redirect.\n");
	if (list)
		free(list);
	return (1);

}

int	cmd_validity(char **tab)
{
	int	*list = NULL;

	list = tab_pos_red(tab);
	if (!list)
		return (0);
	if (check_redir(list, tab) == 1)
		return (1);
	if (check_missing_redir(list, tab) == 1)
		return (1);
	if (check_recurrence_redir(list, tab) == 1)
		return (1);
	if (list[0] == 0) {
		if (tab_redir(tab[list[0] + 1]) == 0 &&
		tab_redir(tab[list[0] + 2]) == 0);
		else
			return (msg_redir(list, 2));
	}
	return (0);
}