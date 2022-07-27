/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** catch signals
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

int	check_errno(mysh_t *ms)
{
	if (errno == EACCES || errno == ENOEXEC) {
		er_putstr(ms->arg[0]);
		my_rprintf(": Exec format error.");
		my_rprintf(" Wrong Architecture.\n");
		return (1);
	}
	return (0);
}

int	status_handling(int status)
{
	int	ret = 0;

	if (WIFSIGNALED(status)) {
		if (status == 11 || status == 139) {
			er_putstr("Segmentation fault\n");
			ret = 139;
		}
		if (status == 8 || status == 136) {
			er_putstr("Floating exception\n");
			ret = 136;
		}
	}
	if (WIFEXITED(status) == 0)
		return (ret);
	return (WEXITSTATUS(status));
}