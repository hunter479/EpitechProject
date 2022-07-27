/*
** EPITECH PROJECT, 2017
** matchstick
** File description:
** function needed to do the square
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

char	*my_strset(char	*str, int size)
{
	char	*tmp = malloc(sizeof(char) * size + 1);
	int	x = 0;

	if (!tmp)
		return (NULL);
	tmp = my_memset(tmp, 0, sizeof(char) * size + 1);
	for (x = 0; x < size; x += 1)
		tmp[x] = '*';
	tmp[x] = '\0';
	return (tmp);
}

char	*put_stick(char *str, int size, nb_t *nb, int y)
{
	int	a = 1;
	char	*tmp = str;
	int	lm = nb->line - y;

	if (y == 0 || y == nb->line + 1)
		return (tmp);
	while (tmp[a] != '\0' && a != size - 1) {
		if (a > lm && a < size - 1 - lm)
			tmp[a] = '|';
		else
			tmp[a] = ' ';
		a++;
	}
	return (tmp);
}

char	**prep_tab(nb_t *nb)
{
	int	a = 0;
	char	**tmp = malloc(sizeof(char *) * (nb->line + 3));
	int	size = nb->line * 2 + 1;

	if (!tmp)
		return (NULL);
	while (a < nb->line + 2) {
		tmp[a] = my_strset(tmp[a], size);
		if (!tmp[a])
			return (NULL);
		tmp[a] = put_stick(tmp[a], size, nb, a);
		a++;
	}
	tmp[a] = NULL;
	return (tmp);
}
