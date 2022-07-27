/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** inits
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <curses.h>
#include <term.h>
#include "my.h"

void	init_keys(mysh_t *ms)
{
	ms->keys.up_arrow = tigetstr("kcuu1");
	ms->keys.down_arrow = tigetstr("kcud1");
	ms->keys.left_arrow = tigetstr("kcub1");
	ms->keys.right_arrow = tigetstr("kcuf1");
	return;
}

void	init_forfree(mysh_t *ms, char **env)
{
	ms->end = 0;
	ms->ret = 0;
	ms->old_pwd = NULL;
	ms->env = dupenv(env);
	ms->s = NULL;
	return;
}

bt_t	*init_values(mysh_t *ms, char **env, bt_t *bt)
{
	init_forfree(ms, env);
	init_keys(ms);
	ms->patha = my_strcat(getcwd(NULL, 0), "/.42shrc");
	ms->alias = get_alias(ms->patha);
	bt = malloc(sizeof(*bt) * 11);
	bt[0].builtins = &my_cd;
	bt[1].builtins = &my_exit;
	bt[2].builtins = &my_env;
	bt[3].builtins = &my_setenv;
	bt[4].builtins = &my_unsetenv;
	bt[5].builtins = &my_history;
	bt[6].builtins = &my_echo;
	bt[7].builtins = &my_alias;
	bt[8].builtins = &my_unalias;
	bt[9].builtins = &my_alias_saver;
	bt[10].builtins = NULL;
	return (bt);
}

hisflag_t	init_hisflags(hisflag_t flags)
{
	flags.c = 0;
	flags.h = -42;
	flags.r = -42;
	flags.nb = 0;
	return (flags);
}
