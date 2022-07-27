/*
** EPITECH PROJECT, 2018
** 104intersection
** File description:
** check
*/

#include "intersection.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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

int	first_disp(inter_t nbr)
{
	if (nbr.opt < 1 || nbr.opt > 3)
		return (-1);
	if (nbr.opt == 1)
		printf(sphere, nbr.p);
	if (nbr.opt == 2)
		printf(cylinder, nbr.p);
	if (nbr.opt == 3)
		printf(cone, nbr.p);
	printf(def, nbr.xp, nbr.yp, nbr.zp);
	printf(def2, nbr.xv, nbr.yv, nbr.zv);
}
