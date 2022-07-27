/*
** EPITECH PROJECT, 2017
** my_strcmp.c
** File description:
** CPool_Day06_2017_Task05
*/

#include "my.h"

int     straliascmp(char const *s1, char const *s2)
{
	int     i = 0;
	int	n = 6;

	while (s1[i] != '\0' && s2[n] != '\0' && s1[i] == s2[n]) {
		i++;
		n++;
	}
	if (s1[i] == '\0' && s2[n] == '=')
		return (0);
	return (1);
}
