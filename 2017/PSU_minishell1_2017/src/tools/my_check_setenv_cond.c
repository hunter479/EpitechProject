/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** list of check for setenv for name
*/

#include <unistd.h>
#include "my.h"

int	first_letter(char c)
{
	if (c <= 64 || (c >= 91 && c <= 96 && c != '_') || c >= 123) {
		my_printf("setenv: Le nom de la variable");
		my_printf(" doit commencer par une lettre.\n");
		return (-1);
	}
	return (1);
}

int	check_setenv(char *name)
{
	int	a = 0;

	if (first_letter(name[0]) == -1)
		return (-1);
	while (name[a] != '\0') {
		if ((name[a] >= 'A' && name[a] <= 'Z') || name[a] == '_')
			a++;
		else if ((name[a] >= 'a' && name[a] <= 'z') || isnum(name[a]))
			a++;
		else {
			my_printf("setenv: Le nom de la variable");
			my_printf(" ne doit contenir");
			my_printf(" que des caractères alphanumériques.\n");
			return (-1);
		}
	}
	return (1);
}
