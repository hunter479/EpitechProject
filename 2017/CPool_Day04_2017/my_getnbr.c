/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** CPool_Day04_2017_Task05
*/

#include <unistd.h>

int	my_getnbr(char const *str)
{
	int ta = 0;
	int to = 0;
	int nega = 1;

	while (str[ta] == '+' || str[ta] == '-')
	{
		if (str[ta] == '-')
			nega = nega * -1;
		ta = ta + 1;
	}
	while (str[ta] >= '0' && str[ta] <= '9')
	{
		to = to * 10 + (str[ta = ta + 1] - '0');
		if (to < 0)
			to = 0;
	}
	return (to * nega);
}
			
		
