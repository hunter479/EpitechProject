/*
** EPITECH PROJECT, 2017
** BSQ
** File description:
** main.c
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "bsq.h"
#include "my.h"

int	nbr_of_y(char *str)
{
	int	a = -1;
	int	y = 0;

	while (str[++a])
		if (str[a] == '\n')
			y++;
	return (y);
}

int	nbr_of_x(char *str)
{
	int	i = 0;

	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

void	read_it(char *grate)
{
	char		**final;
	matrix_t	mz;
	int		x = 0;
	int		y = 0;

	final = prep(grate, &mz);
	while (y < mz.height) {
		x = 0;
		while (x < mz.width) {
			if (mz.width - x >= mz.s && mz.height - y >= mz.s) {
				while (found_sq(final, &mz, &x, y) != -1)
					(mz.s)++;
			}
			x++;
		}
		y++;
	}
	draw_it(mz, final);
}

int	get_size(char *path)
{
	int		size = 0;
	struct stat	file;

	stat(path, &file);
	size = file.st_size;
	return (size);
}

int	main(int ac, char **av)
{
	char	*grate = malloc(sizeof(char *) * (get_size(av[1]) + 1));
	int	fd = open(av[1], O_RDONLY);
	int	offset = 0;

	if (!grate)
		return (84);
	if (fd == -1)
		return (84);
	offset = read(fd, grate, (get_size(av[1]) + 1));
	grate[offset] = '\0';
	read_it(grate);
	close(fd);
	return (0);
}
