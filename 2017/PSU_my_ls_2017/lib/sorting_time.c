/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** functions to sort by modification time
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

int	get_modif(struct stat file)
{
	int	i = file.st_mtim.tv_sec;

	return (i);
}

char	*dest_add_src(char *dest, char *src)
{
	char	*tmp = NULL;
	int	i = -1;
	int	j = -1;

	if (!dest || !src)
		return (NULL);
	tmp = malloc(sizeof(char *) * (my_strlen(dest) + my_strlen(src) + 1));
	if (!tmp)
		return (NULL);
	while (++i < (my_strlen(dest) + my_strlen(src)))
		tmp[i] = '0';
	i = -1;
	while (dest[++i])
		tmp[i] = dest[i];
	tmp[i ++] = ' ';
	while (src[++j]) {
		tmp[i ++] = src[j];
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*cut_str(char *str, int a)
{
	int	i = 0;

	while (i <= a) {
		i++;
		str++;
	}
	return (str);
}

void	tri_date(stack_t **tmp, char *path)
{
	struct	stat	file;
	int		i = 0;
	char		*nbr = NULL;

	stat((*tmp)->data, &file);
	i = get_modif(file);
	nbr = int_to_charstr(i);
	(*tmp)->data = dest_add_src(nbr, (*tmp)->data);
}

void	sort_by_time(stack_t **id, char *path)
{
	stack_t	*tmp = (*id);
	int	a = 0;

	while (tmp) {
		tri_date(&tmp, path);
		tmp = tmp->next;
	}
	sort(&(*id), 't');
	my_rev_list(&(*id));
	tmp = *id;
	while (tmp) {
		tmp->data = cut_str(tmp->data, 10);
		tmp = tmp->next;
	}
}