/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** function to transform a int into a str
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char	*my_strset(int i, char c)
{
	int	a = 0;
	char	*str = malloc(sizeof(char *) * i);
	while (a < i + 1) {
		str[a] = c;
		a++;
	}
	return (str);
}

int	nega_or_not_nega(int *nbr)
{
	if (*nbr < 0) {
		(*nbr) *= -1;
		return (-1);
	}
	else
		return (1);
}

int	sizeof_nbr(int nbr)
{
	int	i = 0;

	while (nbr > 0) {
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*int_to_str(int nbr)
{
	int	i = 0;
	char	*str;
	int	nega = nega_or_not_nega(&nbr);

	if (nbr == 0)
		return ("0");
	i = sizeof_nbr(nbr);
	str = my_strset(i, '0');
	str[i + 1] = '\0';
	while (i >= 0) {
		str[i] = (nbr % 10) + '0';
		nbr /= 10;
		i--;
	}
	if (nega == -1)
		str[0] = '-';
	else
		str++;
	return (str);
}
