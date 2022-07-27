/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** no multi ppipe or redirect
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

void	wrong_direction(mysh_t *ms, char *str, int i)
{
	if (((pigrsp(str[i + 1]) == 1 && str[i + 1] != str[i]) ||
		(pigrsp(str[i + 1]) == 2 && pigrsp(str[i + 2]) == 1)) ||
		(pigrsp(str[i + 1]) == 1 && pigrsp(str[i + 2]) == 1))
		ms->ret = my_rprintf("Missing name for redirect.\n");
	else
		ms->ret = 0;
}

int	wrong_redirzero(mysh_t *ms, char *str, int i)
{
	if ((pigrsp(str[i + 1]) == 1 && str[i + 1] != str[i])
		|| (pigrsp(str[i + 1]) == 2 && pigrsp(str[i + 2]) == 1))
		ms->ret = my_rprintf("Missing name for redirect.\n");
	else if ((pigrsp(str[i + 1]) == 1 && pigrsp(str[i + 2]) == 1)
		|| (str[i + 1] == str[i] && str[i + 2] == ' ' &&
		pigrsp(str[i + 3]) == 1))
		ms->ret = my_rprintf("Missing name for redirect.\n");
	else
		ms->ret = check_invalid(ms, str);
	return (ms->ret);
}

int	wrong_redir(mysh_t *ms, char *str, int i)
{
	if (i == 0)
		ms->ret = wrong_redirzero(ms, str, i);
	else if (!str[i + 1])
		ms-> ret = my_rprintf("Missing name for redirect.\n");
	else
		wrong_direction(ms, str, i);
	return (ms->ret);
}

int	wrong_pipe(mysh_t *ms, char *str, int i)
{
	if (i == 0 || !str[i + 1])
		ms->ret = my_rprintf("Invalid null command.\n");
	else if ((str[i + 1] == ' ' || str[i + 1] == str[i]) &&
		str[i + 2] == str[i])
		ms->ret = my_rprintf("Invalid null command.\n");
	else
		ms->ret = 0;
	return (ms->ret);
}

int	no_multi(mysh_t *ms, char *str)
{
	for (int i = 0; str[i] != '\0'; i ++) {
		if (str[i] == '<' || str[i] == '>') {
			ms->ret = (good_format(str) == 0) ? ambigo(ms, str) : 0;
			ms->ret = (ms->ret != 1) ? wrong_redir(ms, str, i) : 1;
		}
		else
			ms->ret = (str[i] == '|') ? wrong_pipe(ms, str, i) : 0;
		if (ms->ret == 1)
			return (ms->ret);
	}
	return (ms->ret);
}
