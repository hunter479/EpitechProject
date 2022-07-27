/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** CPool_Day04_2017_Task03
*/

#include <unistd.h>

int	my_strlen(char const *str)
{
	int l;
	l = 0;
	while (str[l] != '\0')
		l = l + 1;
	return (l);
}
