/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** get the first number a string
*/

#include "my.h"
#include <stdio.h>

int	my_getnbr(char const *str)
{
	int	a = 0;
	int	nbr = 0;
	int	nega = 1;

	while (str[a] < '0' && str[a] > '9' && str[a] != '\0' && str[a] != '-')
		a++;
	if (str[a] == '-') {
		nega *= -1;
		a++;
	}
	while (isnum(str[a])) {
		nbr = nbr * 10 + (str[a] - '0');
		if (nbr < 0)
			nbr = 0;
		a++;
	}
	return (nbr * nega);
}
