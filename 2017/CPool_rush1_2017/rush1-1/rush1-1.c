/*
** EPITECH PROJECT, 2017
** rush.c
** File description:
** CPool_rush1_2017
*/

#include <unistd.h>

int	horizontal(int x)
{
	int xa = 0;

	if (xa < x)
	{
		
		my_putchar('o');
		if (x != 1) {
			while (xa != x - 2)
			{
				xa = xa + 1;
				my_putchar('-');
			}
			my_putchar('o');
			my_putchar('\n');
		}
		else
			my_putchar('\n');
	}
	return (x);
}

void	vertical(int x, int y)
{
	int yb = 0;
	int ya = 0;

	while (yb < y - 2)
	{
		my_putchar('|');
		ya = 0;
		while (ya != x - 2)
		{	
			my_putchar(' ');
			ya = ya + 1;
		}
		if (x != 1)
			my_putchar('|');
		my_putchar('\n');
		yb = yb + 1;
	}
}


void	rush (int x, int y)
{
	if ( x <= 0 || y <= 0)
		write(2, "Invalid size\n", 13);
	if (y == 1 && x == 1) {
		my_putchar('o');
		my_putchar('\n');
	}
	else
	{
		horizontal(x);
		vertical(x, y);
		if ( y != 1)
			horizontal(x);
	}
}

