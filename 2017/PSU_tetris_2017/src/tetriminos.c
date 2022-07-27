/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** function for tetris
*/

#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include "struct.h"
#include "proto.h"
#include "my.h"

void	recup_info(tetri_t *it, char *file_name, char *s)
{
	if (file_name)
		it->name = get_name(file_name);
	if (s) {
		it->x = getsize_x(s);
		it->y = getsize_y(s);
		it->color = getcolor(s);
		it->form = malloc((it->y + 100) * 10);
		free(s);
	}
	return;
}

int	ret_form(tetri_t *it, int a, char *file_name, int lengh_ok)
{
	it->form[a] = NULL;
	if (a == it->y && lengh_ok == 1)
		return (0);
	it = error_it(it, file_name);
	return (-1);
}

void	is_wrong(int a, char *file_name, tetri_t *it)
{
	it->form[a] = NULL;
	it = error_it(it, file_name);
	return;
}

int	recup_form(tetri_t *it, char *s, int fd, char *file_name)
{
	int	a = 0;
	int	lengh_ok = 0;
	int	bool = 0;

	s = get_next_line(fd);
	if (!s) {
		is_wrong(a, file_name, it);
		return (-1);
	}
	while (s) {
		if (check_line_form(s) == -1) {
			is_wrong(a, file_name, it);
			return (-1);
		}
		lengh_ok = line_is_good(&bool, s, lengh_ok, it);
		it->form[a] = s;
		s = get_next_line(fd);
		a++;
	}
	return (ret_form(it, a, file_name, lengh_ok));
}

tetri_t	*get_tetriminos(char *path)
{
	DIR	*repo = NULL;
	tetri_t	*to_ret = NULL;

	repo = opendir(path);
	if (repo)
		to_ret = get_info(repo, path);
	if (to_ret)
		sort(&to_ret);
	return (to_ret);
}
