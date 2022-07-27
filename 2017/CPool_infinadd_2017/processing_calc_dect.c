/*
** EPITECH PROJECT, 2017
** infin_add
** File description:
** calc
*/

#include "my.h"
#include <stdlib.h>
#include "infin_add.h"

int	bigger(char *str1, char *str2)
{
	int	a = 0;
	int	b = 0;
	int	d = 0;

	while (str1[a] != '\0') {
		b = str1[a] + b;
		a++;
	}
	a = 0;
	while (str2[a] != '\0') {
		d = str2[a] + d;
		a++;
	}
	if (b > d)
		return (1);
	else if (d > b)
		return (0);
	else
		return (2);
}

int	nbr_cmp(char *str1, char *str2, int i, int j)
{
	int	a = 0;
	int	b = 0;
	int	c = 0;

	while (str1[a] != '\0' || str2[b] != '\0') {
		while (str1[a] == str2[b]) {
			a++;
			b++;
		}
		if (str1[a] > str2[b] && i == j) {
			c = 0;
			return (c);
		}
		if (str1[a] < str2[b] && i == j) {
			c = 1;
			return (c);
		}
		a++;
		b++;
	}
}

char	*my_strset(char *str1, char *str2)
{
	char	*str;
	int	i = my_strlen(str1) - 1;
	int	a = 0;
	int	j = my_strlen(str2) - 1;
	int	d = 0;

	if (i >= j)
		d = i + 1;
	else
		d = j + 1;
	str = malloc(sizeof(char) * (d + 3));
	while (a < d + 2) {
		str[a] = '0';
		a++;
	}
	str[d + 2] = '\0';
	return (str);
}

void	no_neg(char **str1, char **str2, int *m1, int *m2)
{
	while (*str1[0] == '-' || *str1[0] == '+' || *str1[0] == '0') {
		if (*str1[0] == '-')
			*m1 = -1;
		(*str1)++;
	}
	while (*str2[0] == '-' || *str2[0] == '+' || *str2[0] == '0') {
		if (*str2[0] == '-')
			*m2 = -1;
		(*str2)++;
	}
}

char	*my_calc(char *somme, char *str1, char *str2, int m1)
{
	int	i = my_strlen(str1) - 1;
	int	j = my_strlen(str2) - 1;
	int	k = 0;

	if (m1 == 1)
		somme = mmsigne(somme, str1, str2, &k);
	if (m1 == -1 && i > j)
		somme = diffsigne(somme, str1, str2, &k);
	if (m1 == -1 && i < j)
		somme = diffsigne2(somme, str1, str2, &k);
	if (m1 == -1 && i == j &&  nbr_cmp(str1, str2, i, j) == 1)
		somme = diffsigne2(somme, str1, str2, &k);
	if (m1 == -1 && i == j &&  nbr_cmp(str1, str2, i, j) == 0)
		somme = diffsigne(somme, str1, str2, &k);
	return (somme);
}