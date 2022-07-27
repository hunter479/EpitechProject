/*
** EPITECH PROJECT, 2017
** my_print_comb2
** File description:
** CPool_Day03_2017_Task06
*/

#include <unistd.h>


void	my_putchar(char c);

int	loop(void);

const int a = 48;
const int b = 48;
const int k = 48;
const int d = 49;
const int sup = 1;

int func(void)
{
	if (!sup)
	{
		my_putchar(44);
		my_putchar(32);
	}
	my_putchar(a);
	my_putchar(b);
	my_putchar(32);
	my_putchar(k);
	my_putchar(d);
	d = d + 1;
	sup = 0;
}

int my_print_comb2(void)
{
	while (a <= 57)
	{
		while (b <= 57)
		{
			loop();
		}
		b = 48;
		d = b + 1;
		a = a + 1;
		k = a;
	}
	return (0);
}

int loop(void)
{
	while (c <= 57)
	{
		while (d <= 57)
		{
			func();
		}
		k = k + 1;
		d = 48;
	}
	
	b = b + 1;
	d = b + 1;	
	k = a;
}
