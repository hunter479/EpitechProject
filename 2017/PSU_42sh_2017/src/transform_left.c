/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** transform pipe
*/

#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

int	write_fordoubleleft(char **tab)
{
	mode_t	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	int	fd;
	char	*file = my_strdup(". ");

	fd = open(file, O_RDWR | O_TRUNC | O_CREAT, mode);
	if (fd == -1) {
		error_msg(file);
		return (1);
	}
	for (int i = 0; tab[i] != NULL; i ++) {
		write(fd, tab[i], my_strlen(tab[i]));
		write(fd, "\n", 1);
	}
	close(fd);
	return (0);
}

int	simple_left(mysh_t *ms)
{
	int	fd;

	fd = open(ms->file, O_RDONLY);
	if (fd == -1) {
		error_msg(ms->file);
		return (ms->ret = 1);
	}
	dup2(fd, 0);
	close(fd);
	return (ms->ret = 0);
}

int	double_left(mysh_t *ms)
{
	char	*s = NULL;
	char	**tab = NULL;

	while (my_strcmp(s, ms->file) != 0) {
		my_printf("? ");
		s = get_next_line(0);
		tab = add_str_totab(tab, s);
	}
	tab[size_tab(tab) - 1] = NULL;
	for (int i = 0; tab[i] != NULL; i ++)
		ms->ret = write_fordoubleleft(tab);
	ms->file = my_strdup(". ");
	ms->ret = simple_left(ms);
	if (open(". ", O_RDONLY) != -1)
		remove(". ");
	return (ms->ret);
}

int	do_left(mysh_t *ms, bt_t *bt, int b, int sd)
{
	if (sd == 1)
		ms->ret = simple_left(ms);
	else if (sd == 2)
		ms->ret = double_left(ms);
	if (ms->ret == 1)
		return (1);
	if (isthere_apip(ms) == 1 || isthere_apip(ms) == 2) {
		ms->file = find_file(ms->red, '>');
		sd = simple_ordouble(ms->red, '>');
		ms->red = arg_woutred(ms->red, '>');
		ms->red = tab_dup(ms->red, 1);
		ms->ret = do_right(ms, bt, b, sd);
	}
	else if (isthere_apip(ms) == 5) {
		ms->arg = tab_dup(ms->red, 0);
		ms->ret = transform_pipe(ms, bt);
	}
	else
		ms->ret = before_exec(ms, bt);
	return (ms->ret);
}

int	transform_left(mysh_t *ms, bt_t *bt)
{
	char	*builtin[6] = {"cd", "exit", "env", "setenv", "unsetenv", NULL};
	int	b = -1;
	int	sd = 0;

	sd = simple_ordouble(ms->arg, '<');
	ms->file = find_file(ms->arg, '<');
	ms ->arg = arg_woutred(ms->arg, '<');
	ms->red = tab_dup(ms->arg, 0);
	ms->arg = isthere_another(ms, ms->arg);
	for (int i = 0; builtin[i] != NULL; i ++)
		if (my_strcmp(builtin[i], ms->arg[0]) == 0)
			b = i;
	if (b == -1) {
		if (check_argccess(ms) == 0)
			return (ms->ret = do_left(ms, bt, b, sd));
		else
			return (ms->ret = 1);
	}
	else
		return (ms->ret = do_left(ms, bt, b, sd));
}