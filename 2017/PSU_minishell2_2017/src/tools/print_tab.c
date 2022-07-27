/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** function to print a tab
*/

#include <unistd.h>
#include "proto.h"
#include "struct.h"
#include "my.h"

void	print_tab(char **tab)
{
	int	a = 0;

	while (tab && tab[a] != NULL) {
		my_putstr(tab[a]);
		my_putchar('\n');
		a++;
	}
	return;
}