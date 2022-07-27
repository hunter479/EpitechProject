/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** stats
*/

#include "my_ls.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <stdio.h>

char	entity_type(char *pathname)
{
	struct	stat	dir;

	if (lstat(pathname, &dir) == -1)
		return (0);
	if (S_ISDIR(dir.st_mode))
		return ('d');
	if (S_ISREG(dir.st_mode))
		return ('-');
	if (S_ISLNK(dir.st_mode))
		return ('-');
	if (S_ISBLK(dir.st_mode))
		return ('b');
	if (S_ISCHR(dir.st_mode))
		return ('c');
	return ('-');
}

int	sym_link(char *path)
{
	struct	stat file;
	ssize_t	buff = file.st_size + 1;
	char	*linkname = malloc(buff);
	ssize_t	r = readlink(path, linkname, buff);

	lstat(path, &file);
	if (r == -1) {
		perror("");
		exit(84);
	}
	linkname[r] = '\0';
	my_printf("%s -> %s", path, linkname);
	if (r == buff) {
		my_printf("(Returned buffer may have been truncated)\n");
		exit (84);
	}
	free(linkname);
}

long	total_block(stack_t *list, char *path)
{
	long	i = 0;
	struct stat file;

	while (list) {
		stat(list->data, &file);
		if (list->data[0] != '.')
			i += file.st_blocks;
		list = list->next;
	}
	i = i / 2;
	my_printf("total %d\n", i);
	return (i);
}

char	*get_stats(char *path, int to_disp)
{
	struct stat	file;
	char		*rights;
	int		link;
	char		*id;
	int		size;
	char		*date;

	lstat(path, &file);
	rights = get_rights(file, path);
	link = get_link(file);
	id = get_id(file);
	size = get_size(file);
	date = get_date(file, to_disp);
}