/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** list of check for setenv for name
*/

#include <unistd.h>
#include "proto.h"
#include "struct.h"
#include "my.h"

int	my_isalpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	check_value(char *s)
{
	int	a = 0;

	if (!s)
		return (-1);
	while (s[a] != '=' && s[a] != '\0')
		a++;
	if (s[a + 1] == '\0')
		return (-1);
	else
		return (1);
}

int	first_letter(char c)
{
	if (c < 0 || my_isalpha(c) || c == '_' || c > 126)
		return (1);
	else {
		my_putstr_rr("setenv: Variable name must ");
		my_putstr_rr("begin with a letter.\n");
		return (-1);
	}
}

int	check_setenv(char *name)
{
	int	a = 0;

	if (first_letter(name[0]) == -1)
		return (-1);
	else
		name++;
	while (name[a] != '\0') {
		if (isnum(name[a]) || my_isalpha(name[a]) || name[a] == '_')
			a++;
		else if (name[a] < 0)
			a++;
		else {
			my_putstr_rr("setenv: Variable name must");
			my_putstr_rr(" contain alphanumeric characters.\n");
			return (-1);
		}
	}
	return (1);
}
