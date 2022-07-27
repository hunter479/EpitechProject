/*
** EPITECH PROJECT, 2018
** mnishell1
** File description:
** main
*/

#include <stdlib.h>
#include "proto.h"
#include "struct.h"
#include "my.h"

sh_t	init_sh(char **env)
{
	sh_t	sh;

	sh.status = 0;
	sh.home = NULL;
	sh.oldpwd = NULL;
	sh.oldfd = 1;
	sh.newfd = 1;
	sh.env = my_tab_dup(env);
	return (sh);
}

int	main(int ac, char **av, char **env)
{
	sh_t	sh;

	if (ac != 1 || av[1] != NULL)
		return (84);
	if (env[0] == NULL) {
		env = malloc(sizeof(char *) * 1);
		env[0] = NULL;
	}
	my_shell_printing(2);
	sh = init_sh(env);
	my_sig();
	loop(sh);
	return (0);
}
