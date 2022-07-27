/*
** EPITECH PROJECT, 2018
** clear_redir
** File description:
** clear redir
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	nb_redir(char *s)
{
	int	a = 0;
	int	k = 0;

	while (s[a] != '\0') {
		if (s[a] == '>' || s[a] == '<')
			k++;
		a++;
	}
	return (k);
}

char	*with_space(char *str, char *tmp, int *i, int *a)
{
	if (*i != 0 && str[*i - 1] != ' ') {
		tmp[*a] = ' ';
		*a += 1;
	}
	tmp[*a] = str[*i];
	*i += 1;
	*a += 1;
	tmp[*a] = str[*i];
	*i += 1;
	*a += 1;
	if (*i != 0 && str[*i] != ' ') {
		tmp[*a] = ' ';
		*a += 1;
	}
	return (tmp);
}

char	*without_space(char *str, char *tmp, int *i, int *a)
{
	if (*i != 0 && str[*i - 1] != ' ') {
		tmp[*a] = ' ';
		*a += 1;
	}
	tmp[*a] = str[*i];
	*i += 1;
	*a += 1;
	if (str[*i] != ' ') {
		tmp[*a] = ' ';
		*a += 1;
	}
	return (tmp);
}

char	*sub_clear_redir(char *str, char *tmp, int *i, int *a)
{
	if ((str[*i] == '>' && str[*i + 1] == '>') ||
		(str[*i] == '<' && str[*i + 1] == '<'))
		tmp = with_space(str, tmp, i, a);
	else
		tmp = without_space(str, tmp, i, a);
	return (tmp);
}

char	*clear_redir(char *str)
{
	int	a = 0;
	char	*tmp = NULL;

	tmp = my_malloc(tmp, my_strlen(str) + nb_redir(str) * 4);
	for (int i = 0; str[i]; i += 1) {
		if (str[i] == '>' || str[i] == '<')
			tmp = sub_clear_redir(str, tmp, &i, &a);
		tmp[a] = str[i];
		a += 1;
	}
	tmp[a] = '\0';
	free(str);
	return (tmp);
}