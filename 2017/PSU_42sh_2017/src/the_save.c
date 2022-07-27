/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** the alias saver
*/

#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

void	my_alias_saver(mysh_t *ms)
{
	mode_t	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	int	fd;
	int	save;

	fd = open(ms->patha, O_RDWR | O_TRUNC | O_CREAT, mode);
	if (fd == -1) {
		error_msg(ms->patha);
		ms->ret = 1;
		return;
	}
	save = dup(1);
	dup2(fd, 1);
	for (int i = 0; ms->alias[i]; i += 1) {
		my_putstr(ms->alias[i]);
		write(1, "\n", 1);
	}
	close(fd);
	dup2(save, 1);
	ms->ret = 0;
}