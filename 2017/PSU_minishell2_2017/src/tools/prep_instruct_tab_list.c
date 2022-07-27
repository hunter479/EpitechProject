/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** prep_instruct_tab_list
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "proto.h"
#include "struct.h"

int	inst_len(char *str)
{
	int	a = 0;

	while (str[a] != '\0' && str[a] != ';')
		a++;
	return (a);
}

int	nb_instruct(char *str)
{
	int	a = 0;
	int	k = 1;

	while (str[a] != '\0') {
		if (str[a] == ';')
			k++;
		a++;
	}
	return (k + 1);
}

char	**prep_tab_list(char *str, char **final)
{
	if (!str)
		return (NULL);
	final = my_malloc(final, nb_instruct(str));
	if (!final)
		return (NULL);
	final[0] = my_malloc(final[0], inst_len(str));
	if (!final[0])
		return (NULL);
	return (final);
}

char	**prep_new_inst(char **str, char **final, int *a, int *y)
{
	if ((*str)[0] == ';') {
		final[*y][--(*a)] = '\0';
		*a = 0;
		(*y)++;
		(*str)++;
		(*str)++;
		final[*y] = my_malloc(final[*y], inst_len(*str));
	}
	if (final[*y] == NULL)
		return (NULL);
	else
		return (final);
}

char	**str_to_tab_list(char *str)
{
	char	**final = NULL;
	int	a = 0;
	int	y = 0;

	final = prep_tab_list(str, final);
	if (!final)
		return (NULL);
	while (str[0] != '\0') {
		final[y][a] = str[0];
		a++;
		str++;
		final = prep_new_inst(&str, final, &a, &y);
		if (!final)
			return (NULL);
	}
	final[y][a] = '\0';
	y++;
	final[y] = NULL;
	return (final);
}
