/*
** EPITECH PROJECT, 2018
** my_exit
** File description:
** function that exit the shell, but cleans also
*/

#include <stdlib.h>
#include "my.h"
#include "minishell.h"

void	my_exit(char *s, char ** cmd, sh_t *sh)
{
	free(s);
	clean_tab(cmd);
	clean_tab(sh->env);
	exit(0);
}