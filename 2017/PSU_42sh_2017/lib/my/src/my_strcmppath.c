/*
** EPITECH PROJECT, 2017
** reproducing behavior of a string
** File description:
** smae
*/

#include "my.h"

int	my_strcmpath(char const *s1, char const *s2)
{
	int	i = 0;

	while (s1[i + 1] != '=' && s2[i] != '\0' && s1[i] == s2[i])
		i += 1;
	return (s1[i] - s2[i]);
}
