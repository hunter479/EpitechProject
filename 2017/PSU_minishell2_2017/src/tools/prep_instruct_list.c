/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** prep_instruct_list
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "proto.h"
#include "struct.h"

int	type_redir(char *s)
{
	int	a = 0;
	int	ref = 0;

	while (s[a] != '\0') {
		if (s[a] == '>')
			ref += 1;
		if (s[a] == '<')
			ref += 10;
	}
	if (ref == 1 || ref == 2)
		return (ref);
	else if (ref == 10 || ref == 20)
		return (ref);
	else
		return (-1);
}

void	put_in_list(char *str, inst_t **it)
{
	inst_t	*elem = NULL;
	inst_t	*tail = *it;

	if (!str)
		return;
	elem = malloc(sizeof(inst_t));
	if (!elem)
		return;
	elem->str = my_strdup(str);
	elem->next = NULL;
	if (!tail) {
		*it = elem;
		return;
	}
	while (tail->next)
		tail = tail->next;
	tail->next = elem;
	return;
}

inst_t	*put_inst(char *s, inst_t *it)
{
	char	**tab = NULL;
	int	a = 0;

	if (!s || s[0] == '\0')
		return (NULL);
	if (nb_pipe(s) >= 1)
		s = clear_pipe(s);
	if (nb_redir(s) >= 1)
		s = clear_redir(s);
	s = clean_str(s);
	tab = str_to_tab_list(s);
	while (tab[a]) {
		if (tab[a])
			put_in_list(tab[a], &it);
		a++;
	}
	free(s);
	clean_tab(tab);
	return (it);
}

