/*
** EPITECH PROJECT, 2018
** minishel
** File description:
** space tool
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	how_manyas(char *tmp, int i)
{
	if ((tmp[i + 1] == tmp[i] && tmp[i + 2] != ' ') ||
		tmp[i + 1] != ' ')
		return (3);
	else if ((tmp[i + 1] == tmp[i] && tmp[i + 2] == ' ') ||
		tmp[i + 1] == ' ')
		return (2);
	return (0);
}

int	how_many(char *tmp, int i)
{
	if (i != 0 && tmp[i - 1] != ' ')
		return (how_manyas(tmp, i));
	else if (i == 0 || tmp[i - 1] == ' ') {
		if ((tmp[i + 1] == tmp[i] && tmp[i + 2] != ' ') ||
			tmp[i + 1] != ' ')
			return (2);
		else
			return (1);
	}
	my_printf("ah bon ?\n");
	return (0);
}

int	check_pgs(char *tmp, int i)
{
	if (pigrsp(tmp[i]) != 1)
		return (1);
	else {
		if (i != 0 && tmp[i - 1] == tmp[i])
			return (1);
		else
			return (how_many(tmp, i));
	}
}

int	cpy_pgszero(char *str, int k)
{
	if (k == 0)
		return (0);
	else if (pigrsp(str[k - 1]) != 1)
		return (0);
	else
		return (1);
}

int	cpy_pgs(char *str, int k)
{
	if (pigrsp(str[k]) == 2)
		return (0);
	else if (pigrsp(str[k]) == 0)
		return (cpy_pgszero(str, k));
	else {
		if (k != 0 && pigrsp(str[k - 1]) == 0)
			return (1);
		else
			return (0);
	}
}
