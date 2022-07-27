/*
** EPITECH PROJECT, 2017
** my_strcmp.c
** File description:
** CPool_Day06_2017_Task05
*/

#include <unistd.h>

int	my_strcmp(char const *s1, char const *s2)
{
	int	strcmp = 0;

	while (s1[strcmp] != '\0' && s2[strcmp] != '\0' && s1[strcmp] == s2[strcmp])
		strcmp++;
	return (s2[strcmp] - s1[strcmp]);
}
