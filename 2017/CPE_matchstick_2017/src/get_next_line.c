/*
** EPITECH PROJECT, 2018
** get the next line
** File description:
** gnl
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int	gnl_strlen(char *str)
{
	int	a = 0;

	while (str[a] != '\0')
		a++;
	return (a);
}

void	gnl_cpy(char *dest, char *src, int n)
{
	int	i;

	for (i = 0; src[i] && i < n; i++)
		dest[i] = src[i];
	if (src[i])
		dest[i] = '\0';
	return;
}

char	*transfer(char *final, char *buf, int *begin, int done)
{
	char	*to_mal;
	int	to_fgt;

	final ? to_fgt = gnl_strlen(final) : (to_fgt = 0);
	to_mal = malloc(sizeof(char *) * (to_fgt + done + 1));
	final ? gnl_cpy(to_mal, final, to_fgt) : gnl_cpy(to_mal, "", to_fgt);
	to_mal[to_fgt + done] = 0;
	gnl_cpy(to_mal + to_fgt, buf + *begin, done);
	if (final)
		free(final);
	*begin = *begin + (done + 1);
	return (to_mal);
}

char		*get_next_line(int fd)
{
	static char	buf[100];
	static int	size = 0;
	char		*final = NULL;
	static int	begin = 0;

	for (int done = 0; 1; done += 1) {
		if (size <= begin) {
			begin = 0 + (0 * (done = 0));
			if (!(size = read(fd, buf, 100)))
				return (final);
			if (size == -1)
				return (NULL);
		}
		if (buf[begin + done] == '\n') {
			final = transfer(final, buf, &begin, done);
			return (final);
		}
		if (begin + done == size - 1)
			final = transfer(final, buf, &begin, done + 1);
	}
}
