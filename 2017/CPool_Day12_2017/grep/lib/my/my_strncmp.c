/*
** EPITECH PROJECT, 2017
** my_strncmp.c
** File description:
** CPool_Day06_2017_Task06
*/

#include <unistd.h>

int	my_strncmp(char const *s1, char const *s2, int n)
{
	int	strncmp = 0;
	int	nchar_strncmp = 0;

	while (s1[strncmp] != '\0' && s2[strncmp] != '\0' && s1[strncmp] == s2[strncmp]) {
		if (nchar_strncmp < n - 1)
			nchar_strncmp++;
		strncmp++;
		return (s2[strncmp] - s1[strncmp]);
	}
}
