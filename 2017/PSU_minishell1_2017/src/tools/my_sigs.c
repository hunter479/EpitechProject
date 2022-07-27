/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** function to take care signals
*/

#include "my.h"
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void	signal_handling(int sig)
{
	if (sig == SIGSEGV) {
		my_printf("%s\n", strsignal(sig));
		exit(139);
	}
	if (sig == SIGINT) {
		my_putchar('\n');
		my_shell_printing(1);
	}
	return;
}

void	my_sig(void)
{
	signal(SIGSEGV, signal_handling);
	signal(SIGINT, signal_handling);
	return;
}
