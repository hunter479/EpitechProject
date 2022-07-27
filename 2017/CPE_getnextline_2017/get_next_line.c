/*
** EPITECH PROJECT, 2018
** getnextline
** File description:
** main.c
*/

#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdlib.h>

char	*add_str(char *src, char *to_add, int offset)
{
	int	a = -1;
	int	i = -1;
	char	*final = malloc(sizeof(char *) * (offset + 2));

	if (!final)
		return (NULL);
	final[0] = '0';
	while (final[++a] < offset)
		final[a] = '0';
	a = -1;
	while (src[++a])
		final[a] = src[a];
	while (to_add[++i])
		final[a ++] = to_add[i];
	final[a] = '\0';
	return (final);
}

char	*get_line(char *str, char *stock)
{
	int	a = 0;
	char	*line = NULL;

	while (str[a] && str[a] != '\0')
		a++;
	line = malloc(sizeof(char *) * (a + 5));
	if (!line)
		return (NULL);
	a = 0;
	while (str[a] != '\0' && str[a] != '\n') {
		line[a] = str[a];
		a++;
	}
	if (str[a] == '\n') {
		line[a] == '\n';
		a++;
	}
	line[a] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static	char	*stock;
	char		*to_read = malloc(sizeof(char *) * READ_SIZE + 5);
	char		*ret = NULL;
	int		offset = 0;
	static int		i = 0;

	if (fd == -1 || !(to_read))
		return (NULL);
	if (!stock) {
		stock = malloc(sizeof(char *) * READ_SIZE + 5);
		stock[0] = 0;
	}
	while (offset = read(fd, to_read, READ_SIZE) != 0) {
		if (offset == -1)
			return (NULL);
		ret = get_line(to_read, stock);
		stock = add_str(stock, ret, offset);
		return (ret);
	}
}