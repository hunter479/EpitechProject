/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** trnsform pwd for cd
*/

#include <signal.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

char	*cd_void(char *pwd)
{
	int 	nb = 0;
	int	sl = 0;
	char	*ret;

	for (nb = 0, sl = 0; sl != 3 && pwd[nb] != '\0'; nb ++)
		if (pwd[nb] == '/')
			sl += 1;
	if (sl != 3)
		return (pwd);
	ret = malloc(sizeof(char) * (nb + 1));
	for (nb = 0, sl = 0; sl != 3; nb ++) {
		ret[nb] = pwd[nb];
		if (pwd[nb] == '/')
			sl += 1;
	}
	ret[nb - 1] = '\0';
	return (ret);
}

char	*pwd_wtilde(char *pwd, char *way)
{
	char	*rest = my_strdup(way + 1);
	char	*base = cd_void(pwd);

	if (!rest)
		return (base);
	else
		return (my_strcat(base, rest));
}

void	error_msg(char *str)
{
	er_putstr(str);
	er_putstr(": ");
	er_putstr(strerror(errno));
	if (errno == ENOEXEC)
		er_putstr(". Wrong Architecture");
	er_putstr(".\n");
}

void	the_cd(mysh_t *ms, char *pwd)
{
	if (ms->arg[1][0] == '~') {
		if (chdir(pwd_wtilde(pwd, ms->arg[1])) == -1)
			ms->ret = 1;
		else
			set_oldpwd(ms, pwd);
	}
	else if (my_strcmp(ms->arg[1], "-") == 0) {
		if (chdir(ms->old_pwd) == -1)
			ms->ret = 1;
		else
			set_oldpwd(ms, pwd);
	}
	else {
		if (chdir(ms->arg[1]) == -1)
			ms->ret = 1;
		else
			set_oldpwd(ms, pwd);
	}
	if (ms->ret == 1)
		error_msg(ms->arg[1]);
}