/*
** EPITECH PROJECT, 2018
** 105torus
** File description:
** main
*/

#include "torus.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void	prep(char **av, tor_t *nbr)
{
	nbr->opt = atof(av[1]);
	nbr->a0 = atof(av[2]);
	nbr->a1 = atof(av[3]);
	nbr->a2 = atof(av[4]);
	nbr->a3 = atof(av[5]);
	nbr->a4 = atof(av[6]);
	nbr->n = atof(av[2]);
}

int	is_num(char *str)
{
	int	i = 0;

	while (str[i]) {
		if (str[i] >= '0' & str[i] <= '9' || str[i] == '-')
			i++;
		else
			return (-1);
	}
	return (0);
}

int	rigor(int ac, char **av)
{
	int	i = 1;
	if (ac != 9)
		return (-1);
	while (av[i]) {
		if (is_num(av[i]) == 0)
			i++;
		else
			return (-1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	tor_t	nbr;

	if (rigor(ac, av) == -1)
		return (84);
	prep(av, &nbr);
	if (nbr.opt < 1 || nbr.opt > 3)
		return (84);
	return (0);
}