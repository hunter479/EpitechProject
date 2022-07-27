/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetriminos_heck.
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include "struct.h"
#include "proto.h"
#include "my.h"

int	line_is_good(int *bool, char *s, int lengh_ok, tetri_t *it)
{
	int	lengh = 0;

	lengh = tetri_len_line(s);
	if (lengh == it->x && *bool == 0)
		lengh_ok = 1;
	if (lengh > it->x && *bool == 0) {
		lengh_ok = 0;
		*bool = 1;
	}
	return (lengh_ok);
}

tetri_t	*stock_info(char *file_name, char *path)
{
	int	fd = open(path, O_RDONLY);
	char	*s = NULL;
	tetri_t	*it = malloc(sizeof(tetri_t));

	if (fd == -1)
		return (NULL);
	init_struct(it);
	s = get_next_line(fd);
	if (check_first_line(s) == 0)
		recup_info(it, file_name, s);
	else {
		it = error_it(it, file_name);
		return (it);
	}
	if (it->form)
		if (recup_form(it, s, fd, file_name) == 0)
			it->ok = 1;
	close(fd);
	return (it);
}

tetri_t	*get_info(DIR *repo, char *path)
{
	struct dirent	*file;
	tetri_t	*new = NULL;
	tetri_t	*tmp = NULL;
	char	*f_path = NULL;

	file = readdir(repo);
	while (file) {
		f_path = catpath(path, file->d_name);
		if (check_tetri(file->d_name) == 0) {
			tmp = stock_info(file->d_name, f_path);
			put_in_list(tmp, &new);
		}
		free(f_path);
		file = readdir(repo);
	}
	if (closedir(repo) == -1)
		return (NULL);
	return (new);
}
