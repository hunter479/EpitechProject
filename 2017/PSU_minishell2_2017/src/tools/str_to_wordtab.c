/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** word to tableau
*/

#include <stdlib.h>
#include "proto.h"
#include "struct.h"
#include "my.h"

int	nbr_word(char *str)
{
	int	a = 2;
	int	b = 0;

	while (str[b] != '\0') {
		if (str[b] == ' ')
			a++;
		b++;
	}
	return (a);
}

char	**prep_new_string(char **final, int *i, int *a, char **str)
{
	final[*i][*a] = '\0';
	(*i)++;
	(*str)++;
	*a = 0;
	return (final);
}

char	**tab_prep_tab(char **final, char *str)
{
	final = my_malloc(final, (nbr_word(str) + 1));
	if (!final)
		return (NULL);
	final[0] = my_malloc(str, my_strlen(str) + 2);
	return (final);
}

char	**str_to_tab(char *str)
{
	char	**final = NULL;
	int	i = 0;
	int	a = 0;

	if ((final = tab_prep_tab(final, str)) == NULL)
		return (NULL);
	while (final[i] && str[0] != '\0') {
		final[i][a ++] = str[0];
		str++;
		if (str[0] == ' ' || str[0] == '\t') {
			final = prep_new_string(final, &i, &a, &str);
			final[i] = my_malloc(str, my_strlen(str) + 1);
		}
	}
	final[i ++][a] = '\0';
	final[i] = NULL;
	return (final);
}
