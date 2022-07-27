/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** save_var
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "proto.h"
#include "struct.h"

builtins_t	*init_built(void)
{
	builtins_t	*bt = NULL;

	bt = malloc(sizeof(*bt) * 6);
	if (!bt)
		return (NULL);
	bt[0].cmd = "env";
	bt[0].bt = &command_env;
	bt[1].cmd = "setenv";
	bt[1].bt = &command_setenv;
	bt[2].cmd = "unsetenv";
	bt[2].bt = &command_unsetenv;
	bt[3].cmd = "cd";
	bt[3].bt = &command_cd;
	bt[4].cmd = NULL;
	bt[5].cmd = NULL;
	return (bt);
}

char	*save_var(char *name, char **env, char *val)
{
	int	a = existing_name(name, env);

	if (val)
		free(val);
	if (env[a])
		return (my_strdup(env[a]));
	if (env[a] == NULL)
		return (my_strdup("/"));
	return (NULL);
}