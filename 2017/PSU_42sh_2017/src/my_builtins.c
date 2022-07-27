/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** builtins
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

void	my_cd(mysh_t *ms)
{
	char	*pwd = getcwd(NULL, 0);
	int	ac = size_tab(ms->arg);

	if (ac == 1) {
		chdir(cd_void(pwd));
		set_oldpwd(ms, pwd);
	}
	else if (ac > 2) {
		my_rprintf("%r: Too many arguments.\n", ms->arg[0]);
		ms->ret = 1;
	}
	else
		the_cd(ms, pwd);
	ms->arg = malloc(sizeof(char *) * 4);
	ms->arg[0] = my_strdup("setenv");
	ms->arg[1] = my_strdup("PWD");
	ms->arg[2] = my_strdup(getcwd(NULL, 0));
	ms->arg[3] = NULL;
	my_setenv(ms);
	free(pwd);
}

void	my_exit(mysh_t *ms)
{
	if (!ms->arg[1]) {
		ms->ret = 0;
		ms->end = !ms->end;
	}
	else if (ms->arg[2]) {
		my_rprintf("%r: Expression Syntax.\n", ms->arg[0]);
		ms->ret = 1;
	}
	else
		the_exit(ms);
}

void	my_env(mysh_t *ms)
{
	disp_env(ms);
	ms->ret = 0;
}

void	my_setenv(mysh_t *ms)
{
	int	ac = size_tab(ms->arg);

	if (ac == 1)
		my_env(ms);
	else if (ac > 3) {
		my_rprintf("%r: Too many arguments.\n", ms->arg[0]);
		ms->ret = 1;
	}
	else
		the_setenv(ac, ms);
}

void	my_unsetenv(mysh_t *ms)
{
	int	ac = size_tab(ms->arg);

	if (ac == 1) {
		my_rprintf("%r: Too few arguments.\n", ms->arg[0]);
		ms->ret = 1;
	}
	else
		the_unsetenv(ms);
}