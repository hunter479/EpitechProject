/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** function to get info from the .tretriminos
*/

#include <stdlib.h>
#include <unistd.h>
#include "struct.h"
#include "proto.h"
#include "my.h"

int	getcolor(char *str)
{
	int	color = 0;

	if (!str)
		return (-1);
	while (str[0] != '\0' && isnum(str[0]))
		str++;
	str++;
	while (str[0] != '\0' && isnum(str[0]))
		str++;
	str++;
	color = my_getnbr(str);
	return (color);
}

int	getsize_x(char *str)
{
	int	size = 0;

	if (!str)
		return (-1);
	size = my_getnbr(str);
	return (size);
}

int	getsize_y(char *str)
{
	int	size = 0;

	if (!str)
		return (-1);
	while (str[0] != '\0' && isnum(str[0]))
		str++;
	str++;
	size = my_getnbr(str);
	return (size);
}

char	*get_name(char *str)
{
	int	a = 0;
	char	*name = NULL;

	if (!str)
		return (NULL);
	name = my_malloc(name, my_strlen(str));
	while (str[a] != '.' && str[a] != '\0') {
		name[a] = str[a];
		a++;
	}
	name[a] = '\0';
	return (name);
}