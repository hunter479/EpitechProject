/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** word to tableau
*/

#include <stdlib.h>
#include "my.h"

int	size_word(char *str)
{
	int	a = 0;

	if (!str)
		return (0);
	while (str[a] >= 33 && str[a] <= 126 && str[a] != '\0')
		a++;
	return (a + 3);
}

int	nbr_word(char *str)
{
	int	a = 2;

	while (str[a] != '\0') {
		if (str[0] == ' ')
			a++;
		str++;
	}
	return (a);
}

char	*my_strset(char	*str)
{
	char	*tmp = malloc(sizeof(char) * (size_word(str) + 2));

	if (!tmp)
		return (NULL);
	tmp = my_memset(tmp, 0, sizeof(char) * (size_word(str) + 2));
	return (tmp);
}

char	**prep_new_string(char **final, int *i, int *a, char **str)
{
	final[*i][*a] = '\0';
	(*i)++;
	(*str)++;
	*a = 0;
	return (final);
}

char	**str_to_tab(char *str)
{
	char	**final = malloc(sizeof(char *) * (nbr_word(str) + 2));
	int	i = 0;
	int	a = 0;

	if (!final)
		return (NULL);
	final[i] = my_strset(str);
	while (final[i] && str[0] != '\0') {
		final[i][a ++] = str[0];
		str++;
		if (str[0] == '\0') {
			final[i ++][a] = '\0';
			break;
		}
		if (str[0] == ' ' || str[0] == '\t') {
			final = prep_new_string(final, &i, &a, &str);
			final[i] = my_strset(str);
		}
	}
	final[i] = NULL;
	return (final);
}
