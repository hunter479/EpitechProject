/*
** EPITECH PROJECT, 2017
** matchstick
** File description:
** fonction for verification
*/

#include "my.h"

int	tab_stick(char **tab)
{
	int	a = 0;
	int	b = 0;
	int	compteur = 0;

	if (!tab)
		return (0);
	while (tab[a]) {
		if (tab[a][b] == '|')
			compteur++;
		if (tab[a][b] == '\0') {
			a++;
			b = 0;
		}
		b++;
	}
	return (compteur);
}

int	is_number(char *str)
{
	int	a = 0;

	while (str[a] != '\0') {
		if (str[a] >= '0' && str[a] <= '9')
			a++;
		else
			return (-1);
	}
	return (0);
}
