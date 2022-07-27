/*
** EPITECH PROJECT, 2018
** my_exit
** File description:
** function that exit the shell, but cleans also
*/

#include <stdlib.h>
#include "proto.h"
#include "struct.h"
#include "my.h"

int	my_exit(char **cmd, sh_t *sh, builtins_t *bh)
{
	int	a = 0;

	if (bh)
		free(bh);
	if (cmd) {
		a = cmd[1] ? my_getnbr(cmd[1]) : sh->status;
		clean_tab(cmd);
	} else
		a = sh->status;
	if (sh)
		free_struct(sh);
	exit(a);
}