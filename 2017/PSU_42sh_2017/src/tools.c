/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** add pwd
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

char	*find_file(char **tab, char sep)
{
	int	i = 0;
	char	*ret;

	for (i = 0; *tab[i] != sep && tab[i] != NULL; i ++);
	ret = my_strdup(tab[i + 1]);
	return (ret);
}

int	size_tab(char **tab)
{
	int	ret = 0;

	if (tab == NULL)
		return (0);
	for (ret = 0; tab[ret] != NULL; ret ++);
	return (ret);
}