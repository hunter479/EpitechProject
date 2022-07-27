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

int	check_other(mysh_t *ms)
{
	for (int i = 0; ms->red[i] != NULL; i ++)
		if (pigrsp(*ms->red[i]) == 1)
			return (1);
	return (0);
}

int	return_pipe(mysh_t *ms, bt_t *bt)
{
	if (check_other(ms) == 1) {
		if ((ms->ret = analyze_com(ms, bt)) == 1) {
			exit(1);
			return (ms->ret);
		}
	}
	else {
		if ((ms->ret = before_exec(ms, bt)) == 1) {
			exit(1);
			return (ms->ret);
		}
	}
	return (ms->ret);
}

int	do_pipe(mysh_t *ms, bt_t *bt, int b)
{
	int	fd[2];
	pid_t	pid;

	pipe(fd);
	pid = fork();
	if (pid == 0) {
		dup2(fd[1], 1);
		close(fd[0]);
		ms->ret = do_exec(ms, bt, b);
	}
	else {
		ms->arg = tab_dup(ms->red, 0);
		dup2(fd[0], 0);
		close(fd[1]);
		return (return_pipe(ms, bt));
	}
	return (0);
}

int	transform_pipe(mysh_t *ms, bt_t *bt)
{
	char	*builtin[6] = {"cd", "exit", "env", "setenv", "unsetenv", NULL};
	int	b = -1;

	ms->arg = before_septab(ms->arg, '|');
	ms->red = after_septab(ms->red, '|');
	for (int i = 0; builtin[i] != NULL; i ++)
		if (my_strcmp(builtin[i], ms->arg[0]) == 0)
			b = i;
	if (b == -1 || *ms->arg == NULL) {
		if (check_argccess(ms) == 0)
			ms->ret = do_pipe(ms, bt, b);
		else {
			exit(ms->ret = 1);
			return (ms->ret = 1);
		}
	}
	else
		ms->ret = do_pipe(ms, bt, b);
	return (ms->ret);
}
