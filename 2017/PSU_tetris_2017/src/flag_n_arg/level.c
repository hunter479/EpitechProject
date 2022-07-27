/*
** EPITECH PROJECT, 2018
** checking options
** File description:
** same
*/

#include <stdlib.h>
#include "nick.h"

int	check_level(char *level)
{
	int	i = 0;

	while (level[i] != '\0') {
		if (level[i] < 48 || level[i] > 57)
			return (84);
		i += 1;
	}
	return (0);
}

int	change_level(keys_t *keys, char **av, int j, int i)
{
	if (!av[j + 1])
		return (84);
	else {
		if (check_level(av[j + 1]) == 84)
			return (84);
		keys->level = my_getnbr(av[j + 1]);
		if (keys->level <= 0)
			return (84);
		else
			return (1);
	}
}

int	level_long(keys_t *keys, char **av, int j, int k)
{
	char	*tmp;
	int	i = 0;

	while (av[j][i] != '=')
		i += 1;
	tmp = my_strdup(av[j] + i + 1);
	if (check_level(tmp) == 84)
		return (84);
	keys->level = my_getnbr(tmp);
	if (keys->level <= 0)
		return (84);
	else
		return (0);
}
