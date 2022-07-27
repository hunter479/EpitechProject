/*
** EPITECH PROJECT, 2018
** alias
** File description:
** make your alias
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

int	check_equal(char *alias)
{
	int i = 0;

	while (alias[i] != '=' && alias[i] != '\0')
		i = i + 1;
	if (alias[i] == '\0')
		return (0);
	return (i + 1);
}

char	*new_alias(char *user, char *alias)
{
	char	*new;
	int	i = 0;
	int	n = 0;

	i = check_equal(alias);
	if (i == 0)
		return (user);
	new = malloc(sizeof(char) * (strlen(alias) - i) + 1);
	while (alias[i] != '\0') {
		new[n] = alias[i];
		n = n + 1;
		i = i + 1;
	}
	new[n] = '\0';
	return (new);
}

char	*verifalias(char *user, char **alias)
{
	int i = 0;

	if (alias == NULL)
		return (user);
	while (alias[i] != NULL && straliascmp(user, alias[i]) != 0)
		i = i + 1;
	if (alias[i] != NULL)
		user = new_alias(user, alias[i]);
	return (user);
}

int	check_alias(char **alias)
{
	int i = 0;
	int n = 0;
	int err = 0;

	while (alias[i] != NULL && err == 0) {
		if (strncmp(alias[i], "alias ", 5) != 0)
			err = err + 1;
		if (alias[i][n] == '\0') {
			n = 0;
			i = i + 1;
		}
		n = n + 1;
	}
	alias_error(err);
	return (err);
}

char	**get_alias(char *patha)
{
	int     openfiles = 0;
	char	**alias;

	if (open(patha, O_RDONLY) < 0)
		creat(patha, S_IRWXU);
	openfiles = open(patha, O_RDWR);
	if (openfiles == -1)
		return (NULL);
	alias = take_map(patha);
	if (alias == NULL)
		return (NULL);
	if (check_alias(alias) != 0)
		return (NULL);
	chmod(patha, 00777);
	return (alias);
}