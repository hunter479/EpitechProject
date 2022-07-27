/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** function of check
*/

#include "proto.h"
#include <unistd.h>
#include <stdio.h>

char	**get_name(char **env)
{
	int	a = 0;

	while (env[a] != NULL && my_strncmp("DISPLAY", env[a], 7))
		a++;
	if (env[a] == NULL)
		return (NULL);
	env[a] = my_strdup("DISPLAY=:0.0");
	return (env);
}

int	check(int ac, char **av, char **env)
{
	if (ac != 1 && ac != 2)
		return (-1);
	if (av[1] && my_strncmp(av[1], "-h", 2) == 0) {
		display_ashe();
		return (1);
	}
	if (env && env[0] != NULL)
		env = get_name(env);
	if (env == NULL || env[0] == NULL)
		return (-1);
	if (av[1] != NULL)
		return (-1);
	return (0);
}