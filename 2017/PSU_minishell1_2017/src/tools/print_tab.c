/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** function to print a tab
*/

#include "my.h"
#include <unistd.h>

void	print_tab(char **tab)
{
	int	a = 0;

	while (tab[a] != NULL) {
		my_printf("%s\n", tab[a]);
		a++;
	}
	return;
}