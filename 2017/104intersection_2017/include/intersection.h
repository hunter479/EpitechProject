/*
** EPITECH PROJECT, 2018
** 104intersection
** File description:
** .h for the project
*/

#ifndef INTERSECTION_H_
	#define INTERSECTION_H_

	#define def "straight line going through the (%.lf,%.lf,%.lf) "
	#define	def2 "point and of direction vector (%.lf,%.lf,%.lf)\n"
	#define sphere "sphere of radius %.lf\n"
	#define cylinder "cylinder of radius %.lf\n"
	#define cone "cone of %.lf degree angle\n"

typedef	struct	s_inter
{
	double	opt;
	double	xp;
	double	yp;
	double	zp;
	double	xv;
	double	yv;
	double	zv;
	double	p;
}		inter_t;

typedef	struct	s_result
{
	double	a;
	double	b;
	double	c;
}		result_t;

/* Display and check */
int		is_num(char *);
int		rigor(int, char **);
int		first_disp(inter_t);

/* Calcule */
result_t	calc_sph(inter_t);
result_t	calc_cyl(inter_t);
result_t	calc_cone(inter_t);
void		delta(result_t, inter_t);
void		intersection(inter_t);

/* Other */
void		prep(char **, inter_t *);

#endif /* !INTERSECTION_H_ */
