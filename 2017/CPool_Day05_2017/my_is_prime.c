/*
** EPITECH PROJECT, 2017
** my_is_prime.c
** File description:
** CPool_Day05_Task06
*/

#include <unistd.h>

int	my_is_prime(int nb)
{
	int prime;
	prime = 2;
	if (nb == 0 || nb == 1)
		return (0);
	while (prime < nb) {
		if (nb % prime == 0)
			return (1);
		prime = prime + 1;
	}
	return (1);
}
