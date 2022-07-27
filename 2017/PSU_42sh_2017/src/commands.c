/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** commands
*/

#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

int	analyze_com(mysh_t *ms, bt_t *bt)
{
	int	ret = 0;

	ret = isthere_apip(ms);
	if (ret == 1 || ret == 2)
		ms->ret = transform_right(ms, bt);
	else if (ret == 3 || ret == 4)
		ms->ret = transform_left(ms, bt);
	else {
		if (ret == 5)
			ms->ret = transform_pipe(ms, bt);
		if (ret == 0)
			ms->ret = before_exec(ms, bt);
	}
	return (ms->ret);
}

int	else_analyze(mysh_t *ms, bt_t *bt)
{
	int	w8;

	ms->pid = fork();
	if (ms->pid == 0) {
		if ((ms->ret = analyze_com(ms, bt)) == 1)
			exit(ms->ret);
	}
	else if (waitpid(ms->pid, &w8, WSTOPPED))
		ms->ret = status_handling(w8);
	else
		wait(&w8);
	return (ms->ret);
}

int	analyze_b(mysh_t *ms, bt_t *bt, int b)
{
	if (b == -1 || *ms->arg == NULL) {
		if (check_argccess(ms) == 0) {
			ms->ret = do_exec_zero(ms, bt, b);
		}
		else
			ms->ret = 1;
	}
	else
		do_exec_zero(ms, bt, b);
	return (ms->ret);
}

int	analyze(mysh_t *ms, bt_t *bt)
{
	char	*builtin[11] = {"cd", "exit", "env", "setenv", "unsetenv",
		"history", "echo", "alias", "unalias", "aliassave", NULL};
	int	b = -1;
	int	ret = 0;

	ret = isthere_apip(ms);
	if (ret == 0) {
		for (int i = 0; builtin[i] != NULL; i ++)
			b = (my_strcmp(builtin[i], ms->arg[0]) == 0) ? i : b;
		ms->ret = analyze_b(ms, bt, b);
	}
	else
		ms->ret = else_analyze(ms, bt);
	return (ms->ret);
}
