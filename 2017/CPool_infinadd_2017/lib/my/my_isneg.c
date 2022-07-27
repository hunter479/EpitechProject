/*
** EPITECH PROJECT, 2017
** my_isneg
** File description:
** CPool_Day03_2017_Task04
*/

#include <unistd.h>

void	my_putchar(char);

int	my_isneg(int n)
{
	char	N = 78;
	char	P= 80;

	if (n >= 0)
		my_putchar(P);
	else
		my_putchar(N);
	return (0);
}
