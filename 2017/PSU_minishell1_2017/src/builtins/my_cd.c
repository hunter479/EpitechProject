/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** cd built in
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "minishell.h"

char	*to_user(char *pwd, sh_t sh)
{
	char	*tmp = NULL;
	int 	a = existing_name("HOME", sh.env);

	if (sh.env[a] == NULL)
		return (sh.home);
	tmp = malloc(sizeof(char) * (my_strlen(pwd) + 2));
	if (!tmp)
		return (sh.home);
	tmp = my_memset(tmp, 0, sizeof(char) * (my_strlen(pwd) + 2));
	tmp = my_strcpy(tmp, sh.env[a]);
	while (tmp[0] != '\0' && tmp[0] != '=')
		tmp++;
	if (tmp[0] == '=')
		tmp++;
	return (tmp);
}

char	*my_concate_str(char *dest, char *src)
{
	char	*tmp = NULL;
	int	size = my_strlen(dest) + my_strlen(src);
	int	a = -1;
	int	b = -1;

	if (size == 0)
		return (NULL);
	tmp = malloc(sizeof(char) * (size + 2));
	if (!tmp)
		return (NULL);
	tmp = my_memset(tmp, 0, sizeof(char) * (size + 2));
	while (src[++a] != '\0')
		tmp[a] = src[a];
	while (dest[++b] != '\0') {
		tmp[a] = dest[b];
		a++;
	}
	tmp[a] = '\0';
	return (tmp);
}

void	my_cd(char *s, sh_t *sh)
{
	char	*pwd = NULL;

	pwd = getcwd(NULL, 0);
	if (!s)
		pwd = to_user(pwd, *sh);
	else {
		pwd = my_concate_str("/", pwd);
		pwd = my_concate_str(s, pwd);
	}
	my_printf("pwd = %s\n", pwd);
	if (chdir(pwd) == -1) {
		perror("");
		return;
	}
	return;
}