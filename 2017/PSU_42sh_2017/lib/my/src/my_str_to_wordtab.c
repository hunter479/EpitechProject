/*
** EPITECH PROJECT, 2018
** str to wordtab
** File description:
** same
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	countword(char *str, char sep)
{
	int	i = 0;
	int	n = 1;

	while (str[i] != '\0') {
		if (str[i + 1] == sep)
			n += 1;
		i += 1;
	}
	return (n);
}

int	my_strlent(char *str, char sep)
{
	int	i = 0;

	while ((str[i] != sep) && (str[i] != '\0'))
		i += 1;
	i += 1;
	return (i);
}

char	**my_str_to_wordtab(char *str, char sep)
{
	char	**tab;
	int	i = 0;
	int	a = 0;
	int	b = 0;

	tab = malloc(sizeof(char *) * (countword(str, sep) + 1));
	while (str[i] != '\0') {
		if (str[i] == sep) {
			for (i; (str[i] == sep); i++);
			a += 1;
			b = 0;
		}
		tab[a] = malloc(sizeof(char) * (my_strlent(str + i, sep)));
		while ((str[i] != sep) && (str[i] != '\0'))
			tab[a][b ++] = str[i ++];
		tab[a][b] = '\0';
	}
	tab[a + 1] = NULL;
	return (tab);
}
