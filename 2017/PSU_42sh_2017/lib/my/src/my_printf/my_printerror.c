/*
** EPITECH PROJECT, 2018
** printf
** File description:
** print error
*/

#include <unistd.h>
#include "my.h"

int	er_putchar(char c)
{
	write(2, &c, 1);
	return (1);
}

int	er_putstr(char const *str)
{
	int	p = 0;

	while (str[p] != '\0') {
		er_putchar(str[p]);
		p = p + 1;
	}
	return (p);
}
