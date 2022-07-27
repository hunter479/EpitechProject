/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** isthere a pip
*/


#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

int	is_right(char *red)
{
	if (!red[1])
		return (1);
	else
		return (2);
}

int	is_left(char *red)
{
	if (!red[1])
		return (3);
	else
		return (4);
}

int	is_pipe(char *red)
{
	if (!red[1])
		return (5);
	else
		return (0);
}

int	isthere_apip(mysh_t *ms)
{
	for (int i = 0; ms->red[i] != NULL; i ++) {
		if (*ms->red[i] == '>')
			return (is_right(ms->red[i]));
		if (*ms->red[i] == '<')
			return (is_left(ms->red[i]));
		if (*ms->red[i] == '|')
			return (is_pipe(ms->red[i]));
	}
	return (0);
}
