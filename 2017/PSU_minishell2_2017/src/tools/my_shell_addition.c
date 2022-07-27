/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** verif if is a tty
*/

#include <unistd.h>
#include "proto.h"
#include "struct.h"
#include "my.h"

void	my_shell_printing(int a)
{
	if (isatty(0) == 1) {
		if (a == 1)
			my_putstr("[my_minishell] $> ");
		if (a == 2)
			my_putstr("\t\t\t    [MINISHELL2 PROJECT]\n");
	}
}