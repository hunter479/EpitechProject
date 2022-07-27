/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** CPool_Day04_2017_Task03
*/

#include <unistd.h>

int	my_strlen(char const *str)
{
	int rto = 0;
	
	while (str[rto] != '\0')
		rto = rto + 1;
	return (rto);
}
