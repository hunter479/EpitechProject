/*
** EPITECH PROJECT, 2018
** clear pipe redir
** File description:
** clear pipe and redirections
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	nb_pipe(char *s)
{
	int	a = 0;
	int	pipe = 0;

	while (s[a] != '\0') {
		if (s[a] == '|')
			pipe++;
		a++;
	}
	return (pipe);
}

char	*clean_set_pipe(char *str)
{
	char	*tmp = NULL;

	tmp = my_malloc(tmp, (my_strlen(str) + (nb_pipe(str) * 3)));
	if (!tmp)
		return (NULL);
	tmp = my_memset(tmp, 0, (my_strlen(str) + (nb_pipe(str) + 3)));
	return (tmp);
}

char	*sub_clear_pipe(char *str, char *tmp, int *i, int *b)
{
	if (*i != 0 && str[*i - 1] != ' ' && tmp[*b - 1] != ' ') {
		tmp[*b] = ' ';
		*b += 1;
	}
	tmp[*b] = str[*i];
	*i += 1;
	*b += 1;
	if (*i != 0 && str[*i] != ' ' && tmp[*b] != ' ') {
		tmp[*b] = ' ';
		*b += 1;
	}
	return (tmp);
}

char	*clear_pipe(char *str)
{
	int	i = 0;
	int	b = 0;
	char	*tmp = NULL;

	tmp = clean_set_pipe(str);
	while (str[i]) {
		if (str[i] == '|')
			tmp = sub_clear_pipe(str, tmp, &i, &b);
		else {
			tmp[b] = str[i];
			i += 1;
			b += 1;
		}
	}
	tmp[b] = '\0';
	free(str);
	return (tmp);
}
