/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** tools
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <curses.h>
#include <stdlib.h>
#include "soko.h"

int	nbr_of_y(char *str)
{
	int	a = -1;
	int	y = 0;

	while (str[++a])
		if (str[a] == '\n')
			y++;
	return (y);
}

int	nbr_of_x(char *str)
{
	int	i = 0;

	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

char	**transfer_(char *str)
{
	int	i = 0;
	int	a = 0;
	int	size = nbr_of_x(str) * nbr_of_y(str);
	char	**final = malloc(sizeof(char **) * size);

	final[i] = malloc(sizeof(char *) * size);
	while (str[0] != '\0') {
		final[i][a] = str[0];
		a++;
		str++;
		if (str[0] == '\n') {
			final[i][a] = '\0';
			str++;
			a = 0;
			i++;
			final[i] = malloc(sizeof(char) * size);
		}
	}
	return (final);
}
