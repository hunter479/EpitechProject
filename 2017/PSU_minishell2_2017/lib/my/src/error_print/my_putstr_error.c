/*
** EPITECH PROJECT, 2018
** my_putstr_error
** File description:
** function to print a str in the output error
*/

#include "my.h"

void	my_putstr_rr(char *str)
{
	int	a = 0;

	while (str[a] != '\0') {
		my_putchar_rr(str[a]);
		a++;
	}
	return;
}