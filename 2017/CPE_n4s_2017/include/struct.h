/*
** EPITECH PROJECT, 2018
** struct
** File description:
** struct
*/

#ifndef STRUCT_H_
# define STRUCT_H_

/*************************************************/
/*		  Struct s_val		       	 */
/*						 */
/* Contient toutes les valeurs utilisées pour	 */
/* faire avancer et tourner la voiture;		 */
/*						 */
/* Valeurs:					 */
/* - sleft, sright: Les 2 extrémités du cône	 */
/* de vision de la voiture;			 */
/*						 */
/* - stop: Milieu du cône de vision de		 */
/* la voiture;	 				 */
/*						 */
/* - top, left, right: Moyennes des infos	 */
/* reçues par GET_INFO_LIDAR;			 */
/* left == 11 premières valeurs;		 */
/* top == 11 valeurs suivantes;			 */
/* right == 10 dernières valeurs;		 */
/*						 */
/* - lsize, rsize: Valeurs des côtés de la	 */
/* voiture jusqu'au mur du côté respectif.	 */
/*						 */
/* - mid: résultat du calcul (lsize + rsize) / 2 */
/*************************************************/

typedef struct	s_val
{
	int	sleft;
	int	sright;
	int	stop;
	int	top;
	int	left;
	int	right;
	double	lsize;
	double	rsize;
	double	mid;
} val_t;
#endif /* !STRUCT_H_ */