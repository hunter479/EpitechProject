/*
** EPITECH PROJECT, 2018
** mian
** File description:
** lain
*/

#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "my.h"

void	fill_andor(andor_t **andor, char **tab)
{
	int	ao = 0;

	for (int i = 0; tab[i] != NULL; i ++) {
		ao += (my_strcmp(tab[i], "&&") == 0) ? 1 : 0;
		ao += (my_strcmp(tab[i], "||") == 0) ? 1 : 0;
	}
	if (ao == 0)
		return (my_put_inlistl(tab, 0, andor));
	else
		return (have_andor(andor, tab));
}

int	command(mysh_t *ms, bt_t *bt, char *command)
{
	char	**tab = my_str_to_wordtab(command, ' ');
	andor_t	*andor = NULL;
	andor_t	*cpy = NULL;

	if (*command == '\0')
		return (0);
	have_andor(&andor, tab);
	cpy = andor;
	while (cpy != NULL) {
		ms->arg = tab_dup(cpy->com, 0);
		ms->red = tab_dup(ms->arg, 0);
		ms->ret = analyze(ms, bt);
		ms->ret = analyse_andoret(cpy, ms->ret);
		free_tab(ms->red);
		free_tab(ms->arg);
		if (ms->ret == 1)
			break;
		cpy = cpy->next;
	}
	free_list(andor);
	return (ms->ret);
}

int	send_command(mysh_t *ms, bt_t *bt)
{
	char	*com = NULL;

	ms->com = my_str_to_wordtab(ms->s, ';');
	for (int i = 0; ms->com[i] != NULL; i ++) {
		if (no_multi(ms, ms->com[i]) != 1) {
			com = clear_str(ms->com[i], 1);
			ms->ret = command(ms, bt, com);
			free(com);
		}
	}
	free_tab(ms->com);
	return (ms->ret);
}

int	parse_line(mysh_t *ms, bt_t *bt)
{
	ms->ret = 0;
	if (ms->s[0] == '\0')
		return (ms->ret);
	ms->s = clear_str(ms->s, 0);
	if (ms->s[0] != '\0')
		ms->ret = send_command(ms, bt);
	return (ms->ret);
}

char	**environnement(char **env)
{
	char	**tab = NULL;

	for (int i = 0; env[i] != NULL; i ++)
		if (my_strncmp(env[i], "PATH=", 5) == 0 && strlen(env[i]) > 6)
			tab = my_str_to_wordtab(env[i] + 5, ':');
		else if (my_strncmp(env[i], "PATH=", 5) == 0 &&
			strlen(env[i]) < 6)
			return (NULL);
	return (tab);
}
