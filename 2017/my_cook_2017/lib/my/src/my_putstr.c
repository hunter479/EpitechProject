/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** CPool_Day02_2017_Task02
*/

#include <unistd.h>

int	my_putstr(char const *str)
{
	int	p = 0;
	while (str[p] != '\0') {
		write(1, &str[p], 1);
		p = p + 1;
	}
	return (0);
}
