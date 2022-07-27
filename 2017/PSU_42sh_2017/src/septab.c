/*
** EPITECH PROJECT, 2018
** minihsell
** File description:
** sep tab
*/

#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

char	**before_strtab(char **tab, char *sep)
{
	char	**ret;
	int	i = 0;

	for (i = 0; my_strcmp(tab[i], sep) != 0 && tab[i] != NULL; i ++);
	ret = malloc(sizeof(char *) * (i + 1));
	for (i = 0; my_strcmp(tab[i], sep) != 0 && tab[i] != NULL; i ++)
		ret[i] = my_strdup(tab[i]);
	ret[i] = NULL;
	return (ret);
}

char	**after_strtab(char **tab, char *sep)
{
	char	**ret;
	int	k = 0;
	int	i = 0;

	if (tab[0] == NULL)
		return (tab);
	for (k = 0; my_strcmp(tab[k], sep) != 0 && tab[k] != NULL; k ++);
	i = (size_tab(tab) - k);
	ret = malloc(sizeof(char *) * i);
	for (int j = (k + 1), i = 0; tab[j] != NULL; i ++, j ++)
		ret[i] = my_strdup(tab[j]);
	ret[i - 1] = NULL;
	return (ret);
}

char	**before_septab(char **tab, char sep)
{
	char	**ret;
	int	i = 0;

	for (i = 0; *tab[i] != sep && tab[i] != NULL; i ++);
	ret = malloc(sizeof(char *) * (i + 1));
	for (i = 0; *tab[i] != sep && tab[i] != NULL; i ++)
		ret[i] = my_strdup(tab[i]);
	ret[i] = NULL;
	return (ret);
}

char	**after_septab(char **tab, char sep)
{
	char	**ret;
	int	k = 0;
	int	i = 0;

	if (tab[0] == NULL)
		return (tab);
	for (k = 0; *tab[k] != sep && tab[k] != NULL; k ++);
	i = (size_tab(tab) - k);
	ret = malloc(sizeof(char *) * i);
	for (int j = (k + 1), i = 0; tab[j] != NULL; i ++, j ++)
		ret[i] = my_strdup(tab[j]);
	ret[i - 1] = NULL;
	return (ret);
}