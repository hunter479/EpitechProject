/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** main
*/

#include "framebuffer.h"

int	which_id(char c)
{
	if (c == '1')
		return (1);
	if (c == '2')
		return (2);
	if (c == '3')
		return (3);
	if (c == '4')
		return (4);
	return (-1);
}

int	is_num(char *str)
{
	int	i = -1;

	while (str[i]) {
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (-1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	id = 0;
	if (ac != 2)
		return (84);
	if (av[1][0] == '-') {
		if (index_screensaver(av[1][1]) == -1)
			return (84);
		else
			return (0);
	}
	id = which_id(av[1][0]);
	if (is_num(av[1]) == 0)
		if ((id) == -1)
			return (84);
	if (window(id) == -1)
		return (84);
}