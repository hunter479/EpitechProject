/*
** EPITECH PROJECT, 2018
** 104intersection
** File description:
** main
*/

#include "intersection.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void	prep(char **av, inter_t *nbr)
{
	nbr->opt = atof(av[1]);
	nbr->xp = atof(av[2]);
	nbr->yp = atof(av[3]);
	nbr->zp = atof(av[4]);
	nbr->xv = atof(av[5]);
	nbr->yv	= atof(av[6]);
	nbr->zv = atof(av[7]);
	nbr->p = atof(av[8]);
}

void	intersection(inter_t nbr)
{
	result_t	rs;

	if (nbr.opt == 1)
		rs = calc_sph(nbr);
	if (nbr.opt == 2)
		rs = calc_cyl(nbr);
	if (nbr.opt == 3)
		rs = calc_cone(nbr);
	delta(rs, nbr);
}

int	main(int ac, char **av)
{
	inter_t	nbr;
	if (rigor(ac, av) == -1)
		return (84);
	prep(av, &nbr);
	if (first_disp(nbr) == -1)
		return (84);
	intersection(nbr);
	return (0);
}