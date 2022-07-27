/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** isthere another
*/

#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

char	**isthere_another(mysh_t *ms, char **tab)
{
	if (isthere_apip(ms) == 1 || isthere_apip(ms) == 2)
		return (arg_woutred(tab, '>'));
	if (isthere_apip(ms) == 5)
		return (before_septab(tab, '|'));
	return (tab);
}
