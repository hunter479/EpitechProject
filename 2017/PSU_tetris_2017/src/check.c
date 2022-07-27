/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** function of check
*/

#include <stdlib.h>
#include <unistd.h>
#include "struct.h"
#include "proto.h"
#include "my.h"

tetri_t	*error_it(tetri_t *it, char *name)
{
	if (it) {
		it->name = get_name(name);
		it->ok = -1;
	}
	return (it);
}

int	check_line_form(char *str)
{
	int	a = 0;

	if (!str)
		return (-1);
	while (str[a] != '\0') {
		if (str[a] == '*' || str[a] == ' ')
			a++;
		else
			return (-1);
	}
	return (0);
}

int	skip_nb(char *str, int a)
{
	while (isnum(str[a]) && str[a] != '\0')
		a++;
	return (a);
}

int	check_first_line(char *str)
{
	int	a = 0;
	int	nb_time = 0;

	if (!str)
		return (ERROR);
	while (str[a] != '\0') {
		if (isnum(str[a])) {
			a = skip_nb(str, a);
			nb_time++;
		}
		else if (str[a] == ' ')
			a++;
		else
			return (ERROR);
	}
	if (nb_time == 3)
		return (0);
	else
		return (-1);
}

int	check_tetri(char *str)
{
	int	a = str ? my_strlen(str) : 0;
	char	*extension = ".tetrimino";
	int	k = 0;

	if (!str || str[0] == '.')
		return (-1);
	while (str[a] != '.' && a != 0)
		a--;
	while (str[a] != '\0') {
		if (str[a] == extension[k]) {
			a++;
			k++;
		} else
			return (-1);
	}
	if (k == 10)
		return (0);
	else
		return (-1);
}