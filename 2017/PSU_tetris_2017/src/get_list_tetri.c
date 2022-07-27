/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** function to get list of tetriminos
*/

#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include "struct.h"
#include "proto.h"
#include "my.h"

int	tetri_len_line(char *str)
{
	int	a = str ? my_strlen(str) : 0;

	if (!str)
		return (-1);
	while (str[a] != '*' && a > 0)
		a -= 1;
	return (a + 1);
}

char	*catpath(char *path, char *file)
{
	char	*tmp = NULL;
	int	i = -1;
	int	j = 0;

	if (!file || !path)
		return (NULL);
	tmp = my_malloc(tmp, (my_strlen(path) + my_strlen(file)));
	while (path[++i] != '\0')
		tmp[i] = path[i];
	while (file[j] != '\0') {
		tmp[i] = file[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	return (tmp);
}
