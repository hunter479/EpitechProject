/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** history
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	get_number(char **arg, int k)
{
	int	i = 0;

	if (arg[k + 1] == NULL)
		return (0);
	if (arg[k + 1][0] == '-')
		return (0);
	for (i = 0; arg[k + 1][i] != '\0'; i++) {
		if (arg[k + 1][i] < '0' || arg[k + 1][i] > '9')
			return (-1);
	}
	return (atoi(arg[k + 1]));
}

hisflag_t	get_flags(char **arg)
{
	hisflag_t	flags = init_hisflags(flags);

	for (int i = 0; arg[i] != NULL; i++) {
		if (strcmp(arg[i], "-c") == 0)
			flags.c = 1;
		if (strcmp(arg[i], "-h") == 0)
			flags.h = get_number(arg, i);
		if (strcmp(arg[i], "-r") == 0)
			flags.r = get_number(arg, i);
	}
	if (flags.h > 0)
		flags.nb = flags.h;
	else if (flags.r > 0)
		flags.nb = flags.r;
	return (flags);
}

void	disp_hisline(char **his, hisflag_t flags)
{
	char	**to_show = NULL;
	char	**tab = NULL;
	int	i = 0;

	if (flags.nb > 0)
		to_show = tab_dup(his, (tablen(his) - flags.nb));
	else
		to_show = tab_dup(his, flags.nb);
	if (flags.r >= 0 && tablen(to_show) != 1)
		to_show = rev_tab(to_show);
	for (i = 0; to_show[i] != NULL; i++) {
		tab = my_str_to_wordtab(to_show[i], '\t');
		if (flags.h == -42)
			printf(" %s\t%s\t", tab[0], tab[1]);
		printf("%s\n", tab[2]);
		free(tab);
	}
}

int	his_error(hisflag_t flags)
{
	if (flags.h == -1 || flags.r == -1) {
		write(2, "history: Badly formed number.\n", 30);
		return (-2);
	}
	if (flags.c == 1)
		return (-1);
	if (flags.h > 0 || flags.r > 0)
		return ((flags.h > -42) ? flags.h : flags.r);
	else
		return (0);
}

void	my_history(mysh_t *ms)
{
	hisflag_t	flags = get_flags(ms->arg);
	int	error = his_error(flags);

	if (error == -1) {
		free(ms->his);
		ms->his = NULL;
	}
	else if (error >= 0)
		disp_hisline(ms->his, flags);
}
