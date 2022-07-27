/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** pipe
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "proto.h"
#include "struct.h"
#include "my.h"


int	builtins_pipe(char **cmd, sh_t *sh, builtins_t *bt)
{
	int	a = 0;

	if (!cmd)
		return (1);
	if (my_strcmp(cmd[0], "exit") == 0)
		my_exit(cmd, sh, bt);
	while (my_strcmp(cmd[0], bt[a].cmd) != 0 && a < 5)
		a++;
	if (bt[a].cmd == NULL)
		return (0);
	else {
		sh->status = bt[a].bt(cmd, sh);
		exit(0);
	}
	return (1);
}

void	pipe_cmd(char **cmd, sh_t *sh, builtins_t *bt)
{
	if (builtins_pipe(cmd, sh, bt) == 0)
		sh->status = my_execve(cmd, sh, 1);
}

int	do_pipe(cmd_t *it, sh_t *sh, builtins_t *bt)
{
	int	pipefd[2];
	pid_t	pid;

	if (fork() == 0) {
		pipe(pipefd);
		pid = fork();
		if (pid == 0) {
			dup2(pipefd[1], 1);
			close(pipefd[1]);
			close(pipefd[0]);
			pipe_cmd(it->cmd1, sh, bt);
		} else {
			dup2(pipefd[0], 0);
			close(pipefd[1]);
			close(pipefd[0]);
			pipe_cmd(it->cmd2, sh, bt);
		}
	}
	return (0);
}