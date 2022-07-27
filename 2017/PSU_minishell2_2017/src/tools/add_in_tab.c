/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** add_in_tab
*/

#include <unistd.h>
#include <my.h>
#include <proto.h>

char	**add_in_tab(char **tab, char *s)
{
	int	a = 0;
	char	**tmp = NULL;

	tmp = my_malloc(tmp, size_tab(tab) + 2);
	if (!tab) {
		tmp[0] = my_strdup(s);
		tmp[1] = NULL;
		return (tmp);
	}
	if (!tmp)
		return (NULL);
	while (tab[a]) {
		tmp[a] = my_strdup(tab[a]);
		a++;
	}
	tmp[a ++] = my_strdup(s);
	tmp[a] = NULL;
	clean_tab(tab);
	return (tmp);
}