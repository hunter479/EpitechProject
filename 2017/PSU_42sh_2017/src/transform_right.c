/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** transform pipe
*/

#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

int	simple_right(mysh_t *ms)
{
	mode_t	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	int	fd;

	fd = open(ms->file, O_RDWR | O_TRUNC | O_CREAT, mode);
	if (fd == -1) {
		error_msg(ms->file);
		return (ms->ret = 1);
	}
	dup2(fd, 1);
	close(fd);
	return (ms->ret = 0);
}

int	double_right(mysh_t *ms)
{
	mode_t	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	int	fd;

	fd = open(ms->file, O_RDWR | O_APPEND | O_CREAT, mode);
	if (fd == -1) {
		error_msg(ms->file);
		return (ms->ret = 1);
	}
	dup2(fd, 1);
	close(fd);
	return (ms->ret = 0);
}

int	do_right(mysh_t *ms, bt_t *bt, int b, int sd)
{
	if (sd == 1)
		ms->ret = simple_right(ms);
	else if (sd == 2)
		ms->ret = double_right(ms);
	if (check_other(ms) == 1) {
		ms->file = find_file(ms->red, '<');
		sd = simple_ordouble(ms->red, '<');
		ms->red = arg_woutred(ms->red, '<');
		ms->red = tab_dup(ms->red, 1);
		ms->ret = do_left(ms, bt, b, sd);
	}
	else
		ms->ret = before_exec(ms, bt);
	return (ms->ret);

}

int	simple_ordouble(char **tab, char sep)
{
	int	i = 0;
	for (i = 0; *tab[i] != sep && tab[i] != NULL; i++);
	if (!tab[i][1])
		return (1);
	else
		return (2);
}

int	transform_right(mysh_t *ms, bt_t *bt)
{
	char	*builtin[6] = {"cd", "exit", "env", "setenv", "unsetenv", NULL};
	int	b = -1;
	int	sd = 0;

	sd = simple_ordouble(ms->arg, '>');
	ms->file = find_file(ms->arg, '>');
	ms ->arg = arg_woutred(ms->arg, '>');
	ms->red = tab_dup(ms->arg, 0);
	if (check_other(ms) == 1)
		ms->arg = arg_woutred(ms->arg, '<');
	for (int i = 0; builtin[i] != NULL; i ++)
		b = (my_strcmp(builtin[i], ms->arg[0]) == 0) ? i : b;
	if (b == -1) {
		if (check_argccess(ms) == 0)
			return (ms->ret = do_right(ms, bt, b, sd));
		else
			return (ms->ret = 1);
	}
	else
		return (ms->ret = do_right(ms, bt, b, sd));
}
