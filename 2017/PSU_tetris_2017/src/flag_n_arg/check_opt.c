/*
** EPITECH PROJECT, 2018
** checking options
** File description:
** same
*/

#include <stdlib.h>
#include "nick.h"
#include "proto.h"

int	check_arg(char *str, char *cmp)
{
	int	i = 0;

	if (!str || !cmp)
		return (-1);
	while (str[i] != '\0' && str[i] != '=') {
		if (str[i] != cmp[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_debug_mode(char **av, int j, keys_t *keys)
{
	if (check_arg("-D", av[j]) == 1) {
		keys->debug = 1;
		return (1);
	}
	if (check_arg("--debug", av[j]) == 1) {
		keys->debug = 1;
		return (1);
	}
	return (0);
}

int	check_opt(char **av, int j, keys_t *keys, fl_t *fl)
{
	int	i = 0;
	int	ret = 0;

	while (i != 17) {
		if (check_debug_mode(av, j, keys) == 1)
			ret = -1;
		else if (check_arg(fl[i].cmp, av[j]) == 1) {
			ret = fl[i].flags(keys, av, j, i);
			i += 1;
		}
		else
			i += 1;
		if (ret != 0)
			return (ret);
	}
	return (0);
}

