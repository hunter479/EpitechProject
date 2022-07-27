/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** tools for my_ls
*/

#include "my_ls.h"
#include <stdbool.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

void	errno_d(DIR *repo, char *str, t_flags flags)
{
	if (errno == ENOTDIR) {
		if (flags.l)
			get_stats(str, 1);
		my_printf("%s\n", str);
		return;
	}
	my_printf(ENOTDIR_str, str);
	perror("");
	return;
}

void	flag(t_flags flags, stack_t *files, char *str)
{
	if (!files)
		return;
	if (flags.l)
		get_stats(catpath(str, files->data), 1);
	my_printf("%s\n", files->data);
}

void	flag_d(stack_t **stack, t_flags flags)
{
	if (flags.t)
		sort_by_time(&(*stack), (*stack)->data);
	while (*stack) {
		if (flags.l)
			get_stats((*stack)->data, 1);
		my_printf("%s\n", (*stack)->data);
		(*stack) = (*stack)->next;
	}
}

char	*catpath(char *path, char *file)
{
	char	*tmp;
	int	i = -1;
	int	j = 0;
	int	k;

	if (!file)
		return (0);
	tmp = malloc(sizeof(char *) * (my_strlen(path) + my_strlen(file)));
	while (path[++i] != '\0')
		tmp[i] = path[i];
	tmp[i ++] = '/';
	while (file[j] != '\0') {
		tmp[i] = file[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	return (tmp);
}