/*
** EPITECH PROJECT, 2018
** 104intersection
** File description:
** calcule
*/

#include "intersection.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double	angle(double ang)
{
	return (ang * M_PI / 180);
}

result_t	calc_sph(inter_t nbr)
{
	result_t	rs;

	rs.a = pow(nbr.xv, 2) + pow(nbr.yv, 2) + pow(nbr.zv, 2);
	rs.b = (2 * nbr.xp * nbr.xv) + (2 * nbr.yp * nbr.yv) + (2 * nbr.zp * nbr.zv);
	rs.c = pow(nbr.xp, 2) + pow(nbr.yp, 2) + pow(nbr.zp, 2) - pow(nbr.p, 2);
	return (rs);
}

result_t	calc_cyl(inter_t nbr)
{
	result_t	rs;

	rs.a = (nbr.xv * nbr.xv) + (nbr.yv * nbr.yv);
	rs.b = (2 * nbr.xp * nbr.xv) + (2 * nbr.yp * nbr.yv);
	rs.c = (nbr.xp * nbr.xp) + (nbr.yp * nbr.yp) - (nbr.p * nbr.p);
	return (rs);
}

result_t	calc_cone(inter_t nbr)
{
	result_t	rs;

	rs.a = pow(nbr.xv, 2) + pow(nbr.yv, 2) - pow(nbr.zv, 2) * pow(tan(angle(nbr.p)), 2);
	rs.b = 2 * nbr.xp * nbr.xv + 2 * nbr.yp * nbr.yv  - 2 * nbr.zp * nbr.zv * pow(tan(angle(nbr.p)), 2);
	rs.c = pow(nbr.xp, 2) + pow(nbr.yp, 2) - pow(nbr.zp, 2) * pow(tan(angle(nbr.p)), 2);
	return (rs);
}

void		delta(result_t rs, inter_t nbr)
{
	double		delta = 0;
	double		x1 = 0;
	double		x2 = 0;

	delta = pow(rs.b, 2) - 4 * rs.a * rs.c;
	if (delta == 0 && nbr.opt != 2) {
		printf("1 intersection point :\n");
		x1 = (-(rs.b) / (2 * rs.a));
		printf("(%.3f, %.3f, %.3f)\n", nbr.xp + x1 * nbr.xv, nbr.yp + x1 * nbr.yv, nbr.zp + x1 * nbr.zv);
	}
	if	(delta == 0 && nbr.opt == 2)
		printf("There is an infinite number of intersection points.\n");
	if (delta < 0)
		printf("No intersection point.\n");
	if (delta > 0) {
		printf("2 intersection points :\n");
		x1 = ((-(rs.b) + sqrt(delta)) / (2 * rs.a));
		x2 = ((-(rs.b) - sqrt(delta)) / (2 * rs.a));
		printf("(%.3f, %.3f, %.3f)\n", nbr.xp + x1 * nbr.xv, nbr.yp + x1 * nbr.yv, nbr.zp + x1 * nbr.zv);
		printf("(%.3f, %.3f, %.3f)\n", nbr.xp + x2 * nbr.xv, nbr.yp + x2 * nbr.yv, nbr.zp + x2 * nbr.zv);
	}
	return;
}
