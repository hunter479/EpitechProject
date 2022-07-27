/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** verif if is a tty
*/

#include "my.h"
#include <unistd.h>

void	my_shell_printing(int a)
{
	if (isatty(0) == 1) {
		if (a == 1)
			my_printf("[my_minishell] $> ");
		if (a == 2)
			my_printf("\t\t\t    [MINISHELL1 PROJECT]\n");
		if (a == 3)
			my_printf("exit\n");
	}
}