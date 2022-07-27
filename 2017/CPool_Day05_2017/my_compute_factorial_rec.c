/*
** EPITECH PROJECT, 2017
** my_compute_factorial_rec
** File description:
** CPool_Day05_2017_Task02
*/

#include <unistd.h>

int	my_compute_factorial_rec(int nb)
{
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	if (nb > 0)
		nb = nb * my_compute_factorial_rec(nb - 1);
	return (nb);
}
