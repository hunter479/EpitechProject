/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** CPool_Day02_2017_Task02
*/

#include "my.h"

int	my_putstr(char const *str)
{
	int	p = 0;

	while (str[p] != '\0') {
		my_putchar(str[p]);
		p = p + 1;
	}
	return (p);
}
