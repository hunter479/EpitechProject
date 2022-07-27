/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** get_cmd
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "proto.h"
#include "struct.h"
#include "my.h"

int	detect_redir(char *s)
{
	char *tab[] = {"" , ">", "<", ">>", "<<", "|", NULL};
	int	a = 0;

	if (!s)
		return (-1);
	while (tab[a] && my_strcmp(tab[a], s) != 0)
		a++;
	if (tab[a] == NULL)
		return (-1);
	else
		return (a);
}

char	*get_redir(char **cmd, int a)
{
	char	*tmp = NULL;

	if (cmd && cmd[a])
		tmp = my_strdup(cmd[a]);
	else
		return (NULL);
	return (tmp);
}

char	**get_cmd1(char **cmd, int a)
{
	char	**tmp = NULL;

	if (a > 0)
		a--;
	for (; a > 0 && detect_redir(cmd[a]) == -1; a--);
	if (cmd[a] && detect_redir(cmd[a]) != -1)
		a++;
	for (; cmd[a] && detect_redir(cmd[a]) == -1; a++)
		tmp = add_in_tab(tmp, cmd[a]);
	return (tmp);
}

char	**get_cmd2(char **cmd, int a)
{
	char	**tmp = NULL;

	if (cmd[a + 1])
		a++;
	for (; cmd[a] && detect_redir(cmd[a]) == -1; a++)
		tmp = add_in_tab(tmp, cmd[a]);
	return (tmp);
}