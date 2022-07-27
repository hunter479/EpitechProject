/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** ambigous erro
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

int	ambigous_left(char *str, int i)
{
	while (pigrsp(str[i]) != 0)
		i += 1;
	for (int j = i; str[j] != '\0'; j ++)
		if (str[j] == '<') {
			my_rprintf("Ambiguous input redirect.\n");
			return (1);
		}
	return (0);
}

int	ambigous_pipe(char *str, int i)
{
	while (pigrsp(str[i]) != 0)
		i += 1;
	for (int j = i; str[j] != '\0'; j ++)
		if (str[j] == '<') {
			my_rprintf("Ambiguous input redirect.\n");
			return (1);
		}
	return (0);
}

int	ambigous_right(char *str, int i)
{
	while (pigrsp(str[i]) != 0)
		i += 1;
	for (int j = i; str[j] != '\0'; j ++)
		if (str[j] == '>' || str[j] == '|') {
			my_rprintf("Ambiguous output redirect.\n");
			return (1);
		}
	return (0);
}

int	ambigo(mysh_t *ms, char *str)
{
	for (int i = 0; str[i] != '\0'; i ++) {
		ms->ret = (str[i] == '<') ? ambigous_left(str, i) : 0;
		if (ms->ret == 1)
			return (ms->ret);
		ms->ret = (str[i] == '>') ? ambigous_right(str, i) : 0;
		if (ms->ret == 1)
			return (ms->ret);
		ms->ret = (str[i] == '|') ? ambigous_pipe(str, i) : 0;
		if (ms->ret == 1)
			return (ms->ret);
	}
	return (ms->ret);
}
