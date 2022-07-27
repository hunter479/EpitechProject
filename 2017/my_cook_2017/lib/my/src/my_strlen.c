/*
** EPITECH PROJECT, 2017
** w,dq,dsqm
** File description:
** qsdmkqd
*/

#include <unistd.h>

int	my_strlen(char const *str)
{
	int	rto = 0;

	while (str[rto] != '\0')
		rto = rto + 1;
	return (rto);
}
