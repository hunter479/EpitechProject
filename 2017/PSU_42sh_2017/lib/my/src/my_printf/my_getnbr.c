/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** get the first number a string
*/

#include <stdio.h>
#include "my.h"

int	is_nega(char const *str)
{
	if (str[0] == '-')
		return (-1);
	else
		return (1);
}

int	my_getnbr(char const *str)
{
	int	a = 0;
	int	nbr = 0;
	int	nega = is_nega(str);

	while (isnum(str[a]) && str[a] != '\0') {
		nbr = nbr * 10 + (str[a] - '0');
		if (nbr < 0)
			nbr = 0;
		a++;
	}
	return (nbr * nega);
}
