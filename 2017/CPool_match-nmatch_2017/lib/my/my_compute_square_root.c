/*
** EPITECH PROJECT, 2017
** my_compute_square_root
** File description:
** CPool_Day05_2017_Task05
*/

#include <unistd.h>

int my_compute_square_root(int nb)
{
	int root = 0;
	if (nb <= 0)
		return (0);
	while ((root * root) != nb)
	{
		root = root + 1;
		if ((root * root) > nb)
			return (0);
	}
	return (root);
}
		    
		    
		    
