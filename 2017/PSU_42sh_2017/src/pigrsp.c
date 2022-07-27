/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** pigrsp error
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

int	pigrsp(char c)
{
	if (c == ' ')
		return (2);
	else if (c == '<' || c == '>' || c == '|' || c == '&')
		return (1);
	else
		return (0);
}

int	good_format(char *str)
{
	int	k = 0;
	int	ret = 0;

	while (str[k] != '\0') {
		if (str[k] == '<' || str[k] == '>')
			ret += good_redirect(str, k);
		k += 1;
	}
	return (ret);
}