/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** CPool_Day03_2017_Task07
*/

#include "my.h"

int	my_put_nbr(int nb)
{
	if (nb < 0) {
		my_putchar('-');
		nb = nb * -1;
	}
	if (nb / 10 > 0)
		my_put_nbr(nb / 10);
	my_putchar (nb % 10 + '0');
	return (0);
}
