/*
** EPITECH PROJECT, 2017
** int to char *
** File description:
** take an int and convert it to a char*
*/

#include <stdlib.h>
#include <stdio.h>
#include "n4s.h"

int	nbrlen(int nbr)
{
	int	i = 0;

	if (nbr < 0) {
		i++;
		nbr = nbr * -1;
	}
	else if (nbr == 0)
		return (1);
	while (nbr > 0) {
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char    *int_to_char(int nb)
{
	int     i = nb;
	int     j = 1;
	char    *str;

	for (; nb >= 10; nb = nb / 10, j++);
	nb = i;
	str = malloc(sizeof(char) * j + 1);
	if (str == NULL)
		return (NULL);
	for (i = 0; i < j; i++)
		str[i] = '0';
	str[i] = '\0';
	for (i = 0; str[i] != '\0'; i++) {
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	str[i] = '\0';
	str = my_revstr(str);
	return (str);
}
