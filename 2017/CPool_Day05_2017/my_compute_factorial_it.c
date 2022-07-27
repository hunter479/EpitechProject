/*
** EPITECH PROJECT, 2017
** my_compute_factorial_it
** File description:
** CPool_Day_05_Task01
*/

#include <unistd.h>

int	 my_compute_factorial_it(int nb)
{
	int arg;
	arg = nb;
	if (arg == 0)
		return (1);
	while (arg != 0)
	{
		arg = arg * (nb = nb - 1);
		nb = nb - 1;
	}
	return (nb);
}
