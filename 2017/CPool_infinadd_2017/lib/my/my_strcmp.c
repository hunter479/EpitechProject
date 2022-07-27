/*
** EPITECH PROJECT, 2017
** my_strcmp.c
** File description:
** CPool_Day06_2017_Task05
*/

#include <unistd.h>

int	my_strcmp(char const *s1, char const *s2)
{
	int	s_cmp = 0;

	while (s1[s_cmp] != '\0' && s2[s_cmp] != '\0' && s1[s_cmp] == s2[s_cmp])
		s_cmp++;
	return (s2[s_cmp] - s1[s_cmp]);
}
