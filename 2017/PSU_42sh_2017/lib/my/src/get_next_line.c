/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get the next line
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	my_strlen(char *s)
{
	int	i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

void	my_strncpy(char *dest, char *src, int p)
{
	int	i = 0;

	while (src[i] != '\0' && i < p) {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*mein_cpy(char	**ret, char *str, int *start, int fin)
{
	int	f;
	char	*deter;

	if (*ret)
		f = my_strlen(*ret);
	else
		f = 0;
	deter = malloc(sizeof(char) * f + fin +1);
	if (deter == NULL)
		return (NULL);
	if (*ret)
		my_strncpy(deter, *ret, f);
	else
		my_strncpy(deter, "", f);
	deter[f + fin] = 0;
	my_strncpy(deter + f, str + *start, fin);
	*start = *start + (fin + 1);
	if (*ret)
		free(*ret);
	*ret = deter;
}

int	check_i(int *start, int *fin, int *i, char **ret)
{
	*start = 0;
	*fin = 0;
	*ret = (*i == -1) ? NULL : *ret;
	if (*i == -1)
		return (-1);
	return (*i);
}

char	*get_next_line(int fd)
{
	static	char	tmp[2];
	static	int	start = 0;
	static	int	i = 0;
	char		*ret = NULL;
	int		fin = 0;

	while (1) {
		if (i <= start) {
			i = read(fd, tmp, 2);
			i = check_i(&start, &fin, &i, &ret);
		}
		if (i == 0 || i == -1)
			return (ret);
		if (tmp[start + fin] == '\n') {
			mein_cpy(&ret, tmp, &start, fin);
			return (ret);
		}
		if (start + fin == i - 1)
			mein_cpy(&ret, tmp, &start, fin + 1);
		fin += 1;
	}
}