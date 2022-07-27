/*
** EPITECH PROJECT, 2017
** my_print_digits.c
** File description:
** CPool_Day03_2017_Task03
*/

#include <unistd.h>

void	my_putchar(char c);

int my_print_digits(void)
{
	char o = 48;
	while (o != 57)
	{
		my_putchar(o);
		o + =1;
	}
	return(0);
}
