/*
** EPITECH PROJECT, 2017
** bsq
** File description:
** algo for the project
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "bsq.h"
#include "my.h"

char	**prep(char *grate, matrix_t *mz)
{
	char	**final;

	while (grate[0] != '\n')
		grate++;
	grate++;
	mz->s = 1;
	final = transfer_(grate);
	mz->width = nbr_of_x(grate);
	mz->height = nbr_of_y(grate);
	return (final);
}

int	found_sq(char **grate, matrix_t *matrice, int *x, int y)
{
	int	x2 = 0;
	int	y2 = 0;

	while (x2 < matrice->s) {
		y2 = 0;
		while (y2 < matrice->s) {
			if (grate[y2][x2] == '\0')
				return (-1);
			if (grate[y2 + y][x2 + *x] == 'o') {
				*x += x2;
				return (-1);
			}
			y2++;
		}
		x2++;
	}
	matrice->x = *x;
	matrice->y = y;
	return (*x + y);
}

void	draw_it(matrix_t mz, char **final)
{
	for (int x2 = 0; x2 < (mz.s - 1); x2++)
		for (int y2 = 0; y2 < (mz.s - 1); y2++)
			final[mz.y + y2][mz.x + x2] = 'x';
	for (int i = 0; i < mz.height; i++)
		my_printf("%s\n", final[i]);
}

char	**transfer_(char *str)
{
	int	i = 0;
	int	a = 0;
	int	size = nbr_of_x(str) * nbr_of_y(str);
	char	**final = malloc(sizeof(char **) * size);

	final[i] = malloc(sizeof(char *) * size);
	while (str[0] != '\0') {
		final[i][a] = str[0];
		a++;
		str++;
		if (str[0] == '\n') {
			final[i][a] = '\0';
			str++;
			a = 0;
			i++;
			final[i] = malloc(sizeof(char *) * size);
		}
	}
	return (final);
}
