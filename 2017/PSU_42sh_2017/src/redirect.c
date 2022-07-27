/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** good_redirection
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

int	else_redirect(char *str, int i)
{
	if (str[i + 1] == str[i] && pigrsp(str[i + 2]) == 1)
		return (1);
	else if (str[i + 1] == str[i] && str[i + 2] == ' ' &&
		pigrsp(str[i + 3]) == 1)
		return (1);
	else
		return (0);
}

int	good_redirect(char *str, int i)
{
	if (!str[i + 1])
		return (1);
	if (str[i + 1] == str[i] && !str[i + 2])
		return (1);
	else if (pigrsp(str[i + 1]) == 1 && str[i] != str[i + 1])
		return (1);
	else
		return (else_redirect(str, i));
}
