/*
** EPITECH PROJECT, 2017
** my_putnbr_base
** File description:
** put the base into a string
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

char	*my_nb_base(int nbr, char const *base)
{
	int	b = my_strlen(base);
	int	i = 1;
	int	k = 1;
	int	nega = nega_or_not_nega(&nbr);
	char	*str = my_strset(sizeof_nbr(nbr) * 2 * b, '(');

	while ((nbr / i) >= b)
		i = i * b;
	while (i > 0) {
		str[k] = (base[(nbr / i) % b]);
		i = i / b;
		k++;
	}
	if (nega == -1)
		str[0] = '-';
	else
		str++;
	str[k - 1] = '\0';
	return (str);
}
