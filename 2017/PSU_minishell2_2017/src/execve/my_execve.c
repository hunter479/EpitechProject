/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** function for execve
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>
#include "proto.h"
#include "struct.h"
#include "my.h"

int	is_piped(int a, char **pth, char **args, sh_t *sh)
{
	int	ref = 0;

	if (execve(pth[a], args, sh->env) != -1);
	else {
		file_error(args[0]);
		ref = 1;
		exit(1);
	}
	return (ref);
}

int	is_forked(int a, char **pth, char **args, sh_t *sh)
{
	int	wstatus = 0;
	int	ref = 0;

	sh->pid = fork();
	if (sh->pid == 0) {
		dup2(sh->oldfd, sh->newfd);
		if (execve(pth[a], args, sh->env) != -1);
		else {
			file_error(args[0]);
			exit(1);
			ref = 1;
		}
	} else if (waitpid(sh->pid, &wstatus, WSTOPPED))
		return (analyse_status(wstatus));
	return (ref);
}

int	is_avaible(char **pth, int *a)
{
	if (pth == NULL)
		return (1);
	while (*a < size_tab(pth) && (access(pth[*a], F_OK) != 0))
		(*a)++;
	if (pth[*a] == NULL)
		return (1);
	return (0);
}

int	my_execve(char **args, sh_t *sh, int pipe)
{
	char	**pth = prep_path(args[0], sh);
	int	a = 0;
	int	ref = 0;

	if (is_avaible(pth, &a) == 1) {
		is_cmd_found(args, pth, 0);
		if (pipe == 1)
			exit(1);
		return (1);
	}
	if (pipe == 1)
		ref = is_piped(a, pth, args, sh);
	else
		ref = is_forked(a, pth, args, sh);
	is_cmd_found(args, pth, 1);
	return (ref);
}