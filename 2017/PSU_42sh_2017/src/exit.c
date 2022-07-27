/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** exit
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

void	the_exit(mysh_t *ms)
{
	int	check = 0;

	if (isnum(ms->arg[1][0]) == 1) {
		for (int i = 1; ms->arg[1][i] != '\0'; i ++)
			check += (isnum(ms->arg[1][i]) == 0) ? 1 : 0;
		if (check > 0) {
			my_rprintf("%r: Badly formed number.\n", ms->arg[0]);
			ms->ret = 1;
		}
		else {
			ms->ret = my_getnbr(ms->arg[1]);
			ms->end = !ms->end;
		}
	}
	else {
		my_rprintf("%r: Expression Syntax.\n", ms->arg[0]);
		ms->ret = 1;
	}
}
