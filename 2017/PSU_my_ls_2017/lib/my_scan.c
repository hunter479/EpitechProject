/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** scan
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

void	printing(stack_t *files, char *str, t_flags flags)
{
	if (!files)
		return;
	if (flags.r)
		my_rev_list(&files);
	if (flags.l)
		total_block(files, catpath(str, files->data));
	while (files) {
		if (files->data[0] != '.' && files->data[1] != '.')
			flag(flags, files, str);
		files = files->next;
	}
}

void	to_print(stack_t *content, stack_t *dir, t_flags flags, char *str)
{
	stack_t *merged = NULL;

	if (!content)
		merged = dir;
	if (!dir)
		merged = content;
	else
		merged = to_merge(content, dir);
	if (flags.t)
		sort_by_time(&merged, catpath(str, merged->data));
	printing(merged, str, flags);
}

void	traiting_type(char *str, DIR *repo, t_flags flags)
{
	struct dirent	*file;
	stack_t	*content = NULL;
	stack_t	*dir = NULL;

	while (file = (readdir(repo))) {
		if (entity_type(catpath(str, file->d_name)) == 'd')
			put_in_list(file->d_name, &dir);
		else
			put_in_list(file->d_name, &content);
	}
	to_print(content, dir, flags, str);
	if (closedir(repo) == -1)
		perror("");
}

void	scan_repo(char *str, int a, t_flags flags)
{
	DIR	*repo = NULL;

	if (a > 1)
		my_printf("%s:\n", str);
	if ((repo = opendir(str)) == 0) {
		errno_d(repo, str, flags);
		return;
	}
	traiting_type(str, repo, flags);
}

void	listing(stack_t *stack, t_flags flags)
{
	struct	dirent *file;
	int	a = size_list(stack);

	sort(&stack, 'd');
	if (flags.r)
		my_rev_list(&stack);
	while (stack && flags.d == false) {
		scan_repo(stack->data, a, flags);
		if (stack->next)
			my_printf("\n");
		stack = stack->next;
	}
	if (flags.d == true) {
		flag_d(&stack, flags);
		return;
	}
}