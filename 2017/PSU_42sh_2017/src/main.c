/*
** EPITECH PROJECT, 2018
** mian
** File description:
** lain
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <term.h>
#include <curses.h>
#include <string.h>
#include "my.h"

void	clean_display(int sig)
{
	if (isatty(0) == 1) {
		if (sig == SIGINT)
			my_putstr("\n$> ");
	}
	return;
}

char	*alias(mysh_t ms)
{
	char	*alias;
	char	*tmp;
	char	*fin;
	int	i = 0;

	if (ms.s == NULL || ms.alias == NULL)
		return (ms.s);
	for (i = 0; ms.s[i] != ' ' && ms.s[i] != '\0'; i += 1);
	tmp = strndup(ms.s, i);
	fin = strdup(ms.s + i);
	alias = verifalias(tmp, ms.alias);
	tmp = my_strcat(alias, fin);
	return (tmp);
}

int	loop(mysh_t ms, bt_t *bt)
{
	while (!ms.end) {
		ms.mnv = environnement(ms.env);
		if (isatty(0) == 1) {
			my_putstr("$> ");
			ms.s = getch_line(&ms, ms.env);
		}
		else
			ms.s = get_next_line(0);
		ms.s = alias(ms);
		if (ms.s == NULL) {
			free_loop(ms);
			break;
		}
		ms.his = add_str_totab(ms.his, set_hismember(ms));
		ms.ret = parse_line(&ms, bt);
		wait(NULL);
		free_loop(ms);
	}
	free_struct(ms, bt);
	return (ms.ret);
}

int	main(int ac, char **av, char **env)
{
	mysh_t	ms;
	bt_t	*bt = NULL;

	bt = init_values(&ms, env, bt);
	ms.his = NULL;
	signal(SIGINT, clean_display);
	if (ac != 1 && !av)
		return (0);
	return (loop(ms, bt));
}
