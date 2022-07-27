/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** alias builtins
*/

#include <unistd.h>
#include "my.h"

char	*create_alias(int ac, mysh_t *ms)
{
	char	*ret = my_strdup("alias ");

	ret = my_strcat(ret, ms->arg[1]);
	ret = my_strcat(ret, "=");
	for (int i = 2; i != ac; i += 1) {
		ret = my_strcat(ret, ms->arg[i]);
		if (ac - 1 != i)
			ret = my_strcat(ret, " ");
	}
	return (ret);
}

void	the_alias(int ac, mysh_t *ms)
{
	char	*new_alias = create_alias(ac, ms);
	int	a = 0;

	a = find_alias(ms, ms->arg[1]);
	if (ac == 2)
		ms->arg[2] = "";
	if (a == -1)
		ms->alias = add_in_tab(ms->alias, new_alias);
	if (a >= 0)
		ms->alias[a] = my_strdup(new_alias);
	ms->arg[2] = (ac == 2) ? NULL : ms->arg[2];
}

void	my_alias(mysh_t *ms)
{
	int	ac = size_tab(ms->arg);

	if (ac == 1 && ms->alias != NULL) {
		for (int i = 0; ms->alias[i]; i += 1)
			my_printf("%s\n", ms->alias[i]);
	}
	else if (ac != 1)
		the_alias(ac, ms);
}

void	the_unalias(mysh_t *ms)
{
	int	a = 0;

	for (int i = 1; ms->arg[i] != NULL; i++) {
		a = find_alias(ms, ms->arg[i]);
		if (a < 0);
		else
			ms->alias = delete_env(ms->alias, a);
	}
	ms->ret = 0;
}

void	my_unalias(mysh_t *ms)
{
	int	ac = size_tab(ms->arg);

	if (ac == 1) {
		my_rprintf("%r: Too few arguments.\n", ms->arg[0]);
		ms->ret = 1;
	}
	else
		the_unalias(ms);
}
