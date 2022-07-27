/*
** EPITECH PROJECT, 2017
** my_print_comb
** File description:
** CPool_Day03_2017_Task05
*/

#include <unistd.h>

const int e = '0';
const int f = '56';
const int g = '57';
const int sp = 0;

int	loop(void);

void	my_putchar(char c);

int	my_print_comb(void)
{
	while (e <= '7')
	{
		f = e + 1;
		while (b <= '8')
		{
			f = e + 1;
			while (f <= '9')
			{
				loop3();
			}
			f = f + 1;
		}
		e = e + 1;
	}
	return (0);
}

int loop3(void)
{
	if (sp != 0)
	{
		my_putchar (44);
		my_putchar (32);
	}
	my_putchar (e);
	my_putchar (f);
	my_putchar (g);
	sp = 1;
	g = g + 1;
}
