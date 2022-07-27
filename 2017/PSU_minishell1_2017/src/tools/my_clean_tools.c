/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** cleaning tools
*/

#include "my.h"
#include <stdlib.h>

char	*clean_set(char *str)
{
	char	*tmp = NULL;

	if (!str)
		return (NULL);
	tmp = malloc(sizeof(char) * (my_strlen(str) + 5));
	if (!tmp)
		return (NULL);
	tmp = my_memset(tmp, 0, sizeof(char) * (my_strlen(str) + 5));
	return (tmp);
}

char	*transfer_str(char *str, char *tmp)
{
	int	a = 0;
	int	b = 0;

	while (str[a] != '\0') {
		while (str[a] == ' ' || str[a] == '\t' || str[a] == ';')
			a++;
		while (str[a] >= 33 && str[a] <= 126 && str[a] != ';')
			tmp[b ++] = str[a ++];
		tmp[b ++] = ' ';
	}
	while (tmp[b - 1] == ' ' || tmp[b - 1] == '\t')
		b--;
	tmp[b] = '\0';
	return (tmp);
}

char	*clean_str(char *str)
{
	char	*tmp = NULL;

	if (str[0] == '\0')
		return (str);
	tmp = clean_set(str);
	if (!str)
		return (NULL);
	tmp = transfer_str(str, tmp);
	free(str);
	return (tmp);
}

void	clean_tab(char **tab)
{
	int	a = 0;
	int	b = size_tab(tab);

	while (a < b) {
		free(tab[a]);
		a++;
	}
	free(tab);
	return;
}

void	clean_in_struct(sh_t *sh)
{
	free(sh->path);
	free(sh->home);
	free(sh->pwd);
	sh->path = NULL;
	sh->home = NULL;
	sh->pwd = NULL;
}