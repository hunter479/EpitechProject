/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** cd built in
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "proto.h"
#include "struct.h"
#include "my.h"

char	*to_user(char *pwd, sh_t sh)
{
	char	*tmp = NULL;
	int 	a = existing_name("HOME", sh.env);

	if (sh.env[a] == NULL)
		return (sh.home);
	tmp = my_malloc(tmp, (my_strlen(pwd) + 2));
	if (!tmp)
		return (sh.home);
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
	tmp = my_malloc(tmp, (size + 2));
	if (!tmp)
		return (NULL);
	while (src[++a] != '\0')
		tmp[a] = src[a];
	while (dest[++b] != '\0') {
		tmp[a] = dest[b];
		a++;
	}
	tmp[a] = '\0';
	return (tmp);
}

char	*do_pwd(char *s, char *pwd, sh_t *sh)
{
	if (!s)
		pwd = to_user(pwd, *sh);
	else if (s[0] != '/') {
		pwd = my_concate_str("/", pwd);
		pwd = my_concate_str(s, pwd);
	}
	else
		pwd = s;
	return (pwd);
}

void	my_cd(char *s, sh_t *sh)
{
	char	*pwd = NULL;
	char	*tmp = NULL;

	pwd = getcwd(NULL, 0);
	tmp = getcwd(NULL, 0);
	if (!sh->oldpwd)
		sh->oldpwd = pwd;
	if (s && sh->oldpwd && my_strcmp("-", s) == 0)
		pwd = sh->oldpwd;
	else
		pwd = do_pwd(s, pwd, sh);
	if (chdir(pwd) == -1) {
		file_error(s);
		return;
	}
	sh->oldpwd = my_strdup(tmp);
	return;
}