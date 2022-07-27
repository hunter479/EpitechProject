/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** prep_redir
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "proto.h"
#include "struct.h"
#include "my.h"

int	create_file(int option, char *file, sh_t *sh)
{
	mode_t	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	int	f_simple = O_RDWR | O_TRUNC | O_CREAT;
	int	f_double = O_RDWR | O_APPEND | O_CREAT;

	if (file) {
		if (option == 1)
			sh->oldfd = open(file, f_simple, mode);
		else if (option == 2)
			sh->oldfd = open(file, f_double, mode);
		else {
			sh->oldfd = open(file, O_RDONLY);
			sh->newfd = 0;
		}
		if (sh->oldfd == -1) {
			file_error(file);
			return (-1);
		}
	}
	return (0);
}

int	prep_file(cmd_t *it, sh_t *sh, builtins_t *bt)
{
	int	ref = detect_redir(it->redir);

	if (ref == 1 || ref == 3) {
		if (ref == 1)
			create_file(1, it->cmd2[0], sh);
		else if (ref == 3)
			create_file(2, it->cmd2[0], sh);
		return (1);
	}
	if (ref == 2 || ref == 4) {
		create_file(3, it->cmd2[0], sh);
		return (2);
	}
	if (ref == 5) {
		do_pipe(it, sh, bt);
		return (-1);
	}
	return (0);
}

void	execute_cmd(cmd_t *it, sh_t *sh, builtins_t *bt)
{
	int	ref = 0;

	ref = prep_file(it, sh, bt);
	if (sh->oldfd == -1)
		return;
	if (ref == -1)
		return;
	it->cmd1 = concate_tab(it->cmd1, it->cmd2 + 1);
	simple_cmd(it->cmd1, sh, bt);
}

cmd_t	*cmd_parsing(char **tab, int a)
{
	cmd_t	*elem = NULL;

	elem = malloc(sizeof(cmd_t));
	elem->redir = NULL;
	elem->cmd1 = NULL;
	elem->cmd2 = NULL;
	if (a == 0) {
		elem->cmd1 = get_cmd2(tab, 1);
		elem->cmd2 = add_in_tab(elem->cmd2, tab[1]);
		elem->redir = get_redir(tab, 0);
		return (elem);
	}
	elem->redir = get_redir(tab, a);
	elem->cmd1 = get_cmd1(tab, a);
	elem->cmd2 = get_cmd2(tab, a);
	return (elem);
}

void	cmd_list(char **tab, sh_t *sh, builtins_t *bt)
{
	cmd_t	*cmd = NULL;

	for (int a = 0; tab[a]; a++) {
		if (detect_redir(tab[a]) != -1) {
			cmd = cmd_parsing(tab, a);
			execute_cmd(cmd, sh, bt);
		}
	}
	sh->oldfd = 1;
	sh->newfd = 1;
	return;
}