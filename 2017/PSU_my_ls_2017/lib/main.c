/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** main for my_ls
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

int	size_list(stack_t *list)
{
	int i = 0;

	while (list) {
		list = list->next;
		i++;
	}
	return (i);
}

void	get_flags(char *str, t_flags *flags)
{
	int	i = 0;

	while (str[++i] != '\0')
		if (type_detect(str[i], &(*flags), FLAGS) == -1) {
			my_printf("my_ls: invalid option -- '%c'\n", str[i]);
			exit(84);
		}
}

int	main(int ac, char **av)
{
	int	i = 0;
	stack_t	*stack = NULL;
	t_flags	flags;

	my_memset(&flags, 0, sizeof(flags));
	while (av[++i]) {
		if (av[i][0] == '-')
			get_flags(av[i], &flags);
		else
			put_in_list(av[i], &stack);
	}
	if (!stack)
		put_in_list(".", &stack);
	listing(stack, flags);
	return (0);
}
