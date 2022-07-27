/*
** EPITECH PROJECT, 2018
** get map from file
** File description:
** libc
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	my_error_file(char *str)
{
	write(2, str, my_strlen(str));
	write(2, ": No such file or directory\n", 28);
	return (-1);
}

int	count_lines(char *path, int *mal)
{
	char	*s;
	int	fd = open(path, O_RDONLY);

	if (fd == -1)
		return (my_error_file(path));
	s = get_next_line(fd);
	while (s != NULL) {
		(*mal) += 1;
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
	return (0);
}

char	**get_map(char *path, int lines)
{
	char	*s;
	int	fd = open(path, O_RDONLY);
	char	**tmp = malloc(sizeof(char *) * (lines + 1));
	int	i = 0;

	if (fd == -1 || tmp == NULL)
		return (NULL);
	s = get_next_line(fd);
	while (s != NULL) {
		tmp[i++] = my_strdup(s);
		free(s);
		s = get_next_line(fd);
	}
	tmp[i] = NULL;
	close(fd);
	return (tmp);
}

char	**take_map(char *path)
{
	char	**tmp;
	int	mal = 0;

	if (count_lines(path, &mal) == -1)
		return (NULL);
	tmp = get_map(path, mal);
	if (tmp == NULL || tmp[0] == NULL || tmp[0][0] == '\0')
		return (NULL);
	return (tmp);
}
