/*
** EPITECH PROJECT, 2017
** my_evile_str
** File description:
** CPool_Day04_Task04
*/

#include <unistd.h>

int	strdlen(char const *str)
{
	int i;
	i=0;
	while (str[i] != '\0')
		i = i + 1;
	return (i);
}

char	*my_evil_str(char *str)
{
	int a = 0;
	int b = strdlen(str) - 1;
	int c;
	while (a < b)
	{
		c = str[a];
		str[a] = str[b];
		str[b] = c;
		a = a + 1;
		b = b - 1;
	}
	return (str);
}
