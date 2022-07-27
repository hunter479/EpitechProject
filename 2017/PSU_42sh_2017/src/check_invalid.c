/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** check_invalid
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

int	check_invalid(mysh_t *ms, char *str)
{
	int	i = 0;
	int	c = 0;

	if (str[1] == ' ')
		i = 2;
	else if (str[1] == str[0] && str[2] == ' ')
		i = 3;
	for (int k = i; str[k] != '\0'; k ++)
		if (str[k] == ' ')
			c = 1;
	if (c == 1)
		return (ms->ret = 0);
	else
		return (ms->ret = my_rprintf("Invalid null command.\n"));
}
