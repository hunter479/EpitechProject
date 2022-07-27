/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** function to take care signals
*/

#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include "my.h"
#include "proto.h"
#include "struct.h"

void	signal_handling(int sig)
{
	if (sig == SIGSEGV)
		my_putstr_rr(strsignal(sig));
	if ((sig) == SIGFPE)
		my_putstr_rr(strsignal(sig));
	if (sig == SIGINT) {
		my_putchar('\n');
		my_shell_printing(1);
		return;
	}
	exit(sig);
	return;
}

void	my_sig(void)
{
	signal(SIGSEGV, signal_handling);
	signal(SIGINT, signal_handling);
	signal(SIGFPE, signal_handling);
	return;
}
