/*
** EPITECH PROJECT, 2017
** my_strncmp.c
** File description:
** CPool_Day06_2017_Task06
*/

#include <unistd.h>

int	my_strncmp(char const *s1, char const *s2, int n)
{
	int strn = 0;
	int nchar_strncmp = 0;

	while (s1[strn] != '\0' && s2[strn] != '\0' && s1[strn] == s2[strn]) {
		if (nchar_strncmp < n - 1)
			nchar_strncmp++;
		strn++;
		return (s2[strn] - s1[strn]);
	}
}
