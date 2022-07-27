/*
** EPITECH PROJECT, 2017
** my_compute_power_it
** File description:
** CPool_Day05_2017_Task03
*/

#include <unistd.h>

int	my_compute_power_it(int nb, int p)
{
	if (p == 0)
		return (1);
	if (p < 0)
		return (0);
	else
		while (p != 0)
		{
			nb = nb * nb;
			p = p - 1;
		}
	return (nb);
}
