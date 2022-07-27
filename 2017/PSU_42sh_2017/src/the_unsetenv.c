/*
** EPITECH PROJECT, 2018
** minisell
** File description:
** unsetenv
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

void	the_unsetenv(mysh_t *ms)
{
	int	a = 0;

	for (int i = 1; ms->arg[i] != NULL; i++) {
		a = find_path(ms, ms->arg[i]);
		if (a < 0);
		else
			ms->env = delete_env(ms->env, a);
	}
	ms->ret = 0;
}