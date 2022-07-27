/*
** EPITECH PROJECT, 2017
** my_rev_params.c
** File description:
** CPool_Day07_2017_Task05
*/

#include <unistd.h>

int main(int ac, int **av)
{
	int i = 0;
	
	while (av[i] != NULL)
		i++;
	while (av[i] != av[0])
	{
		i--;
		my_putstr(av[i]);
		my_putchar('\n');
	}
}
			   
		
