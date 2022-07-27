/*
** EPITECH PROJECT, 2018
** mnishell1
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "minishell.h"
#include <sys/wait.h>
#include <signal.h>

int	builtins(char *s, sh_t *sh)
{
	char	**cmd = str_to_tab(s);

	if (my_strcmp(cmd[0], "env") == 0) {
		command_env(cmd, sh->env);
		return (1);
	}
	else if (my_strcmp(cmd[0], "setenv") == 0) {
		command_setenv(cmd, sh);
		return (1);
	}
	if (my_strcmp(cmd[0], "unsetenv") == 0) {
		command_unsetenv(cmd, sh);
		return (1);
	}
	else if (my_strcmp(cmd[0], "cd") == 0) {
		command_cd(cmd, sh);
		return (1);
	}
	if (my_strcmp(cmd[0], "exit") == 0)
		my_exit(s, cmd, sh);
	return (0);
}

void	instuction_entrer(char *s, sh_t *sh)
{
	if (s[0] == '\0')
		return;
	if (builtins(s, sh) == 1)
		return;
	else {
		my_execve(s, sh);
		return;
	}
}

void	loop(char *s, sh_t sh)
{
	while (1) {
		my_shell_printing(1);
		s = get_next_line(0);
		if (s) {
			s = clean_str(s);
			instuction_entrer(s, &sh);
			free(s);
		}
		if (!s) {
			my_shell_printing(3);
			free(s);
			clean_in_struct(&sh);
			exit(0);
		}
		wait(NULL);
	}
}

int	main(int ac, char **av, char **env)
{
	char	*s = NULL;
	sh_t	sh;

	if (ac != 1 || av[1] != NULL)
		return (84);
	if (env[0] == NULL)
		return (NULL);
	my_shell_printing(2);
	my_sig();
	sh.env = my_tab_dup(env);
	save_var(&sh, env);
	loop(s, sh);
	return (0);
}
