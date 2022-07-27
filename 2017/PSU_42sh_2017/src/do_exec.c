/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** do exec
*/

#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

int	do_exec(mysh_t *ms, bt_t *bt, int b)
{
	if (b == -1) {
		if (execve(ms->exe, ms->arg, ms->env) == -1) {
			error_msg(ms->arg[0]);
			exit(ms->ret = 1);
			return (ms->ret = 1);
		}
		if (check_errno(ms) == 1) {
			exit(ms->ret = 1);
			return (ms->ret = 1);
		}
	}
	else {
		bt[b].builtins(ms);
		exit(ms->ret);
		return (ms->ret);
	}
	return (ms->ret);
}

int	do_exec_zerob(mysh_t *ms)
{
	int	w8 = 0;

	ms->pid = fork();
	if (ms->pid == 0) {
		if (execve(ms->exe, ms->arg, ms->env) == -1) {
			error_msg(ms->arg[0]);
			exit(ms->ret = 1);
			return (ms->ret = 1);
		}
		if (check_errno(ms) == 1) {
			exit(ms->ret = 1);
			return (ms->ret = 1);
		}
	}
	else if (waitpid(ms->pid, &w8, WSTOPPED))
		ms->ret = status_handling(w8);
	else
		wait(&w8);
	return (ms->ret);
}

int	do_exec_zero(mysh_t *ms, bt_t *bt, int b)
{
	if (b == -1)
		ms->ret = do_exec_zerob(ms);
	else
		bt[b].builtins(ms);
	return (ms->ret);
}

int	before_exec(mysh_t *ms, bt_t *bt)
{
	char	*builtin[11] = {"cd", "exit", "env", "setenv", "unsetenv",
		"history", "echo", "alias", "unalias", "aliassave", NULL};
	int	b = -1;

	for (int i = 0; builtin[i] != NULL; i ++)
		if (my_strcmp(builtin[i], ms->arg[0]) == 0)
			b = i;
	if (b == -1 || *ms->arg == NULL) {
		if (check_argccess(ms) == 0)
			ms->ret = do_exec(ms, bt, b);
		else
			ms->ret = 1;
	}
	else
		ms->ret = do_exec(ms, bt, b);
	return (ms->ret);
}
