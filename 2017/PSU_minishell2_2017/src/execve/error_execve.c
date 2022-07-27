/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** error
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>
#include "proto.h"
#include "struct.h"
#include "my.h"

void	is_cmd_found(char **args, char **pth, int found)
{
	if (found == 0) {
		my_putstr_rr(args[0]);
		my_putstr_rr(": Command not found.\n");
	}
	if (args)
		clean_tab(args);
	if (pth)
		clean_tab(pth);
	return;
}

int	my_errno(void)
{
	if (errno == ENOEXEC)
		return (1);
	else
		return (0);
}

void	file_error(char *s)
{
	my_putstr_rr(s);
	my_putstr_rr(": ");
	my_putstr_rr(strerror(errno));
	if (my_errno() == 1)
		my_putstr_rr(". Wrong Architecture");
	my_putstr_rr(".\n");
	return;
}

int	signal_status(int ref, int wstatus)
{
	if (wstatus == 139 || wstatus == 11) {
		my_putstr_rr("Segmentation fault");
		ref = 139;
	}
	if (wstatus == 136 || wstatus == 8) {
		my_putstr_rr("Floating exception");
		ref = 136;
	}
	return (ref);
}

int	analyse_status(int wstatus)
{
	int	ret_line = 0;
	int	ref = wstatus == 256 ? 1 : 0;

	if (WIFSIGNALED(wstatus)) {
		ref = signal_status(ref, wstatus);
		ret_line = 1;
	}
	if (WCOREDUMP(wstatus))
		my_putstr_rr(" (core dumped)");
	if (ret_line == 1)
		my_putchar_rr('\n');
	if (WIFEXITED(wstatus) == 0)
		return (ref);
	return (WEXITSTATUS(wstatus));
}