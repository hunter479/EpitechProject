/*
** EPITECH PROJECT, 2017
** infin_add
** File description:
** calc
*/

#include "my.h"
#include "infin_add.h"

char	*mmsigne(char *somme, char *str1, char *str2, int *k)
{
	int	i = my_strlen(str1);
	int	j = my_strlen(str2);
	int	d = my_strlen(somme) - 1;

	while (i >= 0 || j >= 0) {
		if (--i < 0)
			str1[i] = '0';
		if (--j < 0)
			str2[j] = '0';
		somme[d] = (str1[i] - '0') + (str2[j] - '0') + '0' + *k;
		if (somme[d] >= 10 + '0') {
			somme[d] -= 10;
			*k = 1;
		}
		else
			*k = 0;
		d--;
	}
	if (*k != 0)
		somme[d] = *k + '0';
	return (somme);
}

char	*diffsigne(char *somme, char *str1, char *str2, int *k)
{
	int	i = my_strlen(str1) - 1;
	int	j = my_strlen(str2) - 1;
	int	d = my_strlen(somme) - 1;

	while (i >= 0 || j >= 0) {
		if (i < 0)
			str1[i] = '0';
		if (j < 0)
			str2[j] = '0';
		somme[d] = (((str1[i] - '0') - (str2[j] - '0') + '0') + *k);
		if (somme[d] < '0') {
			somme[d] += 10;
			*k = -1;
		}
		else
			*k = 0;
		i--;
		j--;
		d--;
	}
	return (somme);
}

char	*diffsigne2(char *somme, char *str1, char *str2, int *k)
{
	int	i = my_strlen(str1) - 1;
	int	j = my_strlen(str2) - 1;
	int	d = my_strlen(somme) - 1;

	while (i >= 0 || j >= 0) {
		if (i < 0)
			str1[i] = '0';
		if (j < 0)
			str2[j] = '0';
		somme[d] = (((str2[j] - '0') - (str1[i] - '0') + '0') + *k);
		if (somme[d] < '0') {
			somme[d] += 10;
			*k = -1;
		}
		else
			*k = 0;
		i--;
		j--;
		d--;
	}
	return (somme);
}

int	my_checksomme(char *somme, char *str1, char *str2)
{
	int	a = my_strcmp(str1, str2);
	if (a > 0)
		return (0);
	if (a < 0)
		return (1);
}

char	*somme_check(char *somme, char *str1, char *str2, int A1)
{
	int	a = my_checksomme(somme, str1, str2);
	while (somme [1] == '0')
		somme++;
	if (a == 1 && A1 == -1)
		somme[0] = '-';
	if (a == 0 && A1 == -1)
		somme++;
	if (a == 0 && A1 == 1)
		somme[0] = '-';
	if (a == 1 && A1 == 1)
		somme++;
	if (somme[0] == '\0')
		somme[0] = '0';
	if (somme[0] == '-' && somme[1] == '\0')
		somme[0] = '0';
	return (somme);
}
