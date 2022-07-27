/*
** EPITECH PROJECT, 2017
** my_power_compute_rec.c
** File description:
** CPool_Day05_2017_Task04
*/

#include <unistd.h>

int	my_compute_power_rec(int nb, int p)
{
	int	power_rec = 0;

	if (p == 0)
		return (1);
	if (p < 0)
		return (0);
	if (p != p + p) {
		nb = nb * nb;
		p = p + 1;
		my_compute_power_rec(nb, p);
	}
	else
		return (nb);
}
